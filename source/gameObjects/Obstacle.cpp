//
// Created by LENOVO on 11/16/2023.
//

#include "Obstacle.h"
using namespace std;

void Obstacle::handleInput() {
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        y += 48;
    }
}

void Obstacle::draw() {
    DrawRectangle(x, y, width, height, RED);

    if (isMoving) {
        x += direction;
    }
    if(x > 1366 + 50) { // TODO: Load from config file
        Notify();
    }
}