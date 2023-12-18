//
// Created by LENOVO on 11/16/2023.
//

#include "Road.h"
#include "temp.cpp"
#include <random>

double lastTime=0;
bool eventTriggeredLight(double interval)
{
    double currentTime=GetTime();
    if (currentTime-lastTime >=interval)
    {
        lastTime=currentTime;
        return true;
    }
    return false;
}

Road::Road(double x, double y, int numObstacles) : BaseGameObject(x, y) {
    // TODO: Load from config file.
    roadSprite = LoadAseprite("../assets/trafficEnvironment/2_lane.aseprite");
    int randNum = RandomNumber::getInstance().getRandomNumber(0, 1);
    if (randNum) direction = 1;
    else direction = -1;

    int originX = RandomNumber::getInstance().getRandomNumber(
        0,
        BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"]
    );
    
    for (int i = 0; i < numObstacles; i++) {
        Obstacle *obs = new Obstacle(originX, y, direction);
        obs->Attach(this);
        obs->initObstacle();
        obstacles.push_back(obs);
        originX += this->direction * (
            RandomNumber::getInstance().getRandomNumber(10, 200) +
            obs->getWidth() * 2
        );
    }
    this->numObstacles = numObstacles;
    randomLight();

}

void Road::handleInput() {
    // TODO: Update screen speed;
  
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        y += stepSize;
    }
  
    if (hasLight) light->handleInput();
    
    for(Obstacle *obs: obstacles) {
        obs->handleInput();
    }

    
}

void Road::draw() {
//    y += screenSpeed;

//    DrawRectangle(x, y, 1500, 50, BLACK);
    Rectangle rectangle = {(float) x, (float) y, 1500, 50};

    DrawAsepritePro(roadSprite, 0, rectangle, {(float) 0, (float)0}, 0, WHITE);

    
    for(Obstacle *obs: obstacles) {
        obs->draw();
        if(isMainCharDead || isGamePause || (hasLight && light->isRed))
            obs->setMove(false);
        else if ((!hasLight) || ((hasLight) && (!light->isRed))) {
                obs->setMove(true);
        }
    }

    json cfg = BasicConfigInstance::getData(ConfigType::BASIC);

    if(y > (int) cfg["SCREEN"]["SIZE"]["HEIGHT"] + (int) cfg["TEXTURES"]["OUT_SCREEN_OFFSET"]) {
        BaseGameObject::Notify();
    }

    if (hasLight)
    {
        if ((!isMainCharDead)&&(!isGamePause)) lightHandle();
        light->draw();
    }
}

void Road::handleBlockOutOfScreen() {
    // double newPositionX;
    // if (direction == -1)
    //     newPositionX = 1336 + 50;
    // else
    //     newPositionX = obstacles.back()->getX() - 1366 - 50;

    // Obstacle *obs = new Obstacle( newPositionX, y, direction);
    // obs->Attach(this);
    // obs->initObstacle();
    // obstacles.push_back(obs);
    // obstacles.erase(obstacles.begin());

    int screenW = BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"];
    int newX = obstacles[0]->getX();

    if (direction == -1)
        newX = max(
                newX + RandomNumber::getInstance().getRandomNumber(10, 200) + obstacles[0]->getWidth() * 2,
                screenW + 50
        );
    else
        newX = min(
                newX - (RandomNumber::getInstance().getRandomNumber(10, 200) + obstacles[0]->getWidth() * 2),
                -50
        );

    Obstacle *obs = new Obstacle(newX, y, direction);
    obs->Attach(this);
    obs->initObstacle();
    obstacles.insert(obstacles.begin(), obs);
    obstacles.pop_back();
}

void Road::handleCollision() {
    BaseGameObject::Notify(Message::COLLISION);
    for (Obstacle *obs: obstacles) {
        obs->setMove(false);
    }
    
}

void Road::updateMessage(const Message message) {
    if(message == Message::BLOCK_OUT_OF_SCREEN) 
        this->handleBlockOutOfScreen();
    else if(message==Message::COLLISION) 
        this->handleCollision();
}

Road::~Road() {
    for (Obstacle *obs: obstacles) {
        delete obs;
    }
    if (hasLight)
        delete light;

};
void Road::updateMainPos(Rectangle mainPosRect)
{
    for (Obstacle *obs: obstacles)
    {
       // obs->getPos(mainPos.pos,mainPos.size);
       obs->updateMainPos(mainPosRect);
    }
}
void Road::randomLight()
{
    std::default_random_engine randomEngine(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0,99);
    int r=distribution(randomEngine);
    if (r < randomPercentage)
    {
        hasLight=true;
        light= new TrafficLight(x, y);
    }
    else hasLight=false;
}

//void Road::setScreenSpeed(double speed) {
//    screenSpeed = speed;
//    for (Obstacle *obs: obstacles) {
//        obs->setScreenSpeed(speed);
//    }
//}

void Road::lightHandle()
{
    if (hasLight) {
        if (!light->isRed) {
            std::default_random_engine randomEngine(std::random_device{}());
            std::uniform_int_distribution<int> distribution(5,10);
            int interval=distribution(randomEngine);
            if (eventTriggeredLight(double(interval))) {
                light->isRed=true;
            }
        }
        else if (eventTriggeredLight(5)) {
            light->isRed=false;
        }
    }
}

void Road::moveY(double offset) {
    y += offset;
    for(Obstacle *obs: obstacles) {
        obs->moveY(offset);
    }
    if (hasLight)
        light->moveY(offset);
}