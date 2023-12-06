//
// Created by LENOVO on 11/16/2023.
//

#include "Road.h"
#include "temp.cpp"

Road::Road(double x, double y, int numObstacles) : BaseGameObject(x, y) {
    roadSprite = LoadAseprite("../assets/trafficEnvironment/2_lane.aseprite");

    for(int i = 0; i < numObstacles; i++) {
        int randomX = rand() % 500;
        Obstacle *obs = new Obstacle(randomX, y, direction);
        obs->Attach(this);
        obs->initObstacle();
        obstacles.push_back(obs);
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

void Road::updateMessage(const Message message) {
    if(message == Message::BLOCK_OUT_OF_SCREEN) {
        int randomX = rand() % 500;
        cout << randomX << endl;
        // TODO: update last x = last obstacle.x - randomX
        double newPositionX = obstacles[obstacles.size() - 1]->getX() - randomX;
        Obstacle *obs = new Obstacle( newPositionX, y, 1);
        obs ->Attach(this);
        obs->initObstacle();
        obstacles.push_back(obs);
        obstacles.erase(obstacles.begin()); // TODO: Fix this! This is a bug
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
};
void Road::updateMainPos(Rectangle mainPosRect)
{
    for (Obstacle *obs: obstacles)
    {
       // obs->getPos(mainPos.pos,mainPos.size);
       obs->updateMainPos(mainPosRect);
    }
}