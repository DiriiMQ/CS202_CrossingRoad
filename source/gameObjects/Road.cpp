//
// Created by LENOVO on 11/16/2023.
//

#include "Road.h"

Road::Road(int x, int y, int numObstacles) : BaseGameObject(x, y) {

    for(int i = 0; i < numObstacles; i++) {
        int randomX = rand() % 500;
        Obstacle *obs = new Obstacle(randomX, y, direction);
        obs->Attach(this);
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
    }
}

void Road::draw() {
    DrawRectangle(x, y, 1500, 50, BLACK);
    for(Obstacle *obs: obstacles) {
        obs->draw();
    }

    if(y > 768 + 48 * 3) { // TODO: Load from config file.
        BaseGameObject::Notify();
    }
}

void Road::updateMessage(const Message message) {
    if(message == Message::BLOCK_OUT_OF_SCREEN) {
        int randomX = rand() % 20;
        cout << randomX << endl;
        // TODO: update last x = last obstacle.x - randomX
        Obstacle *obs = new Obstacle( randomX, y, 1);
        obs->Attach(this);
        obstacles.push_back(obs);

        obstacles.erase(obstacles.begin()); // TODO: Fix this! This is a bug
    }
}

Road::~Road() {
    for (Obstacle *obs: obstacles) {
        delete obs;
    }
};