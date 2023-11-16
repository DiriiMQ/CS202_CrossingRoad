//
// Created by LENOVO on 11/17/2023.
//

#include "NonRoad.h"

void NonRoad::handleInput() {
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        y += stepSize;
    }
}

void NonRoad::draw() {

    DrawRectangle(x, y, 1500, 50, GREEN);
    if(y > 768 + 48 * 3) { // TODO: Load from config file.
        BaseGameObject::Notify();
    }
}