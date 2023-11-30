//
// Created by LENOVO on 11/16/2023.
//
#pragma once
#include "Obstacle.h"
#include "temp.cpp"

using namespace std;

void Obstacle::handleInput() {

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        y += 48;
    }
}

void Obstacle::draw() {
//    DrawAseprite(*sprite, 4, x, y, WHITE);
    y += screenSpeed;

    DrawRectangle(x, y, width, height, WHITE);

    if (isMoving) {
        x += direction;
    }
    if(x > 1366 + 50) { // TODO: Load from config file
        BaseGameObject::Notify();
    }
}

void Obstacle::initObstacle() {
//    Aseprite temp = LoadAseprite("../assets/vehicle/Bus.aseprite");
//    sprite = new Aseprite(temp);
}

bool Obstacle::checkCollision(Rectangle mainCharacter) {
    return CheckCollisionRecs(
            mainCharacter,
            {(float)x, (float) y,
             (float) width,(float) height}
             );
}
