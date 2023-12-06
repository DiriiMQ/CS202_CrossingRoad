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
//    y += screenSpeed;

    DrawRectangle(x, y, 1500, 50,  Color{122, 182, 120, 255});
//    Rectangle rectangle = {(float) x, (float) y, 1500, 60};

//    DrawAsepritePro(sprite, 0, rectangle, {(float) 0, (float)0}, 0, WHITE);
//    cout << "SPRITE SHAPE: " << GetAsepriteHeight(sprite) << ", " << GetAsepriteWidth(sprite) << endl;
//    for(int i = x; i < 1500; i += 64) {
//        for(int j = y; j < y + 48; j += 12) {
//            DrawAseprite(sprite, 0, i, j, WHITE);
//        }
//    }

//    DrawAseprite(sprite,0, 500, y, WHITE);
//    DrawAse
    if(y > 768 + 48 * 3) { // TODO: Load from config file.
        BaseGameObject::Notify();
    }
}