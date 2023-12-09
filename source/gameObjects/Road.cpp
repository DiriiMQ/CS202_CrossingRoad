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

Road::Road(int x, int y, int numObstacles) : BaseGameObject(x, y) {
    roadSprite = LoadAseprite("../assets/trafficEnvironment/2_lane.aseprite");
    int randNum = rand();
    if (randNum % 2)
        direction = 1;
    else
        direction = -1;

    int prevPosition = direction == 1 ? -300 : 1366 + 300; // TODO: Fix hard code
    for(int i = 0; i < numObstacles; i++) {
        int randomX = rand() % 300;
        randomX = direction == 1 ? randomX : -randomX;
        Obstacle *obs = new Obstacle(prevPosition + randomX, y, direction);
        prevPosition += direction == 1 ? 300 : -300;
        obs->Attach(this);
        obs->initObstacle();
        obstacles.push_back(obs);
    }
    reverse(obstacles.begin(), obstacles.end());

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
    
    if (hasLight)
    {
        if ((!isMainCharDead)&&(!isGamePause)) lightHandle();
        light->draw();
    }

    
    for(Obstacle *obs: obstacles) {
        obs->draw();
        if(isMainCharDead || isGamePause || (hasLight && light->isRed))
            obs->setMove(false);
        else 
        {
            if ((!hasLight) || ((hasLight) && (!light->isRed)))
                obs->setMove(true);
        }
    }

    if(y > 768 + 48 * 3) { // TODO: Load from config file.
        BaseGameObject::Notify();
    }
    
}

void Road::updateMessage(const Message message) {
    if(message == Message::BLOCK_OUT_OF_SCREEN) {
        double newPositionX;

        if (direction == -1)
            newPositionX = 1336 + 100;
        else
            newPositionX = -100;

        Obstacle *obs = new Obstacle( newPositionX, y, direction);
        obs->Attach(this);
        obs->initObstacle();
        obstacles.push_back(obs);
        if (obstacles.size() > numObstacles)
            obstacles.erase(obstacles.begin());
    }
    else if(message==Message::COLLISION) {
        BaseGameObject::Notify(Message::COLLISION);
        for (Obstacle *obs: obstacles) {
            obs->setMove(false);
        }
    }
    
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
    if (r<randomPercentage)
    {
        hasLight=true;
        light=new TrafficLight;
        light->init(x,y);
    }
    else hasLight=false;
}
void Road::lightHandle()
{
    if (hasLight)
    {
        if (!light->isRed)
        {
            std::default_random_engine randomEngine(std::random_device{}());
            std::uniform_int_distribution<int> distribution(5,10);
            int interval=distribution(randomEngine);
            if (eventTriggeredLight(double(interval))) {
                light->isRed=true;
            }
            
        }
        else 
        {
            if (eventTriggeredLight(5))
            {
                light->isRed=false;
            }
        }
    }
}