//
// Created by LENOVO on 11/16/2023.
//

#include "Road.h"
#include "temp.cpp"

Road::Road(double x, double y, int numObstacles) : BaseGameObject(x, y) {
    // TODO: Load from config file.
    roadSprite = LoadAseprite("../assets/trafficEnvironment/2_lane.aseprite");
    int randNum = RandomNumber::getInstance().getRandomNumber(0, 1);
    if (randNum) direction = 1;
    else direction = -1;

    // int prevPosition = -300;
    // for(int i = 0; i < numObstacles; i++) {
    //     int randomX = rand() % 500;
    //     Obstacle *obs = new Obstacle(prevPosition + randomX, y, direction);
    //     prevPosition += randomX;
    //     obs->Attach(this);
    //     obs->initObstacle();
    //     obstacles.push_back(obs);
    // }

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
}

void Road::handleInput() {
    // TODO: Update screen speed;

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        y += stepSize;
    }

    for(Obstacle *obs: obstacles) {
        obs->handleInput();
//        if(!isMoving)
//            obs->setMove(false);
    }
}

void Road::draw() {
//    y += screenSpeed;

//    DrawRectangle(x, y, 1500, 50, BLACK);
    Rectangle rectangle = {(float) x, (float) y, 1500, 50};

    DrawAsepritePro(roadSprite, 0, rectangle, {(float) 0, (float)0}, 0, WHITE);

    for(Obstacle *obs: obstacles) {
        obs->draw();
        if(isMainCharDead)
            obs->setMove(false);
    }

    if(y > 768 + 48 * 3) { // TODO: Load from config file.
        BaseGameObject::Notify();
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
};
void Road::updateMainPos(Rectangle mainPosRect)
{
    for (Obstacle *obs: obstacles)
    {
       // obs->getPos(mainPos.pos,mainPos.size);
       obs->updateMainPos(mainPosRect);
    }
}