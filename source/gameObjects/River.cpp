//
// Created by LENOVO on 11/30/2023.
//

#include "River.h"

void River::handleInput() {

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        y += stepSize;
    }
}

void River::draw() {
    y += screenSpeed;

    DrawRectangle(x, y, 1500, 50, BLUE);
    if(y > 768 + 48 * 3) { // TODO: Load from config file.
        BaseGameObject::Notify();
    }
}