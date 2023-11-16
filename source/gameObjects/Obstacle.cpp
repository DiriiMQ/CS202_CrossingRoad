//
// Created by LENOVO on 11/16/2023.
//

#include "Obstacle.h"
#include <iostream>
using namespace std;

void Obstacle::handleInput() {
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        y += 50;
    }
}

void Obstacle::draw() {
    DrawRectangle(x, y, width, height, RED);

    if (isMoving) {
        cout << "X: " << x << endl;
        x += direction;
    }
}