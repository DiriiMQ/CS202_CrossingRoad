//
// Created by LENOVO on 11/16/2023.
//

#include "Road.h"

Road::Road(int x, int y, int numObstacles) : x(x), y(y) {
    int direction = 1; // will be random

    for(int i = 0; i < numObstacles; i++) {
        int randomX = rand() % 500;
        cout << randomX << endl;
        Obstacle *obs = new Obstacle(randomX, y, direction);
        obstacles.push_back(obs);
    }
}

void Road::handleInput() {
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        y += 50;
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
}

Road::~Road() {
    for (Obstacle *obs: obstacles) {
        delete obs;
    }
};