//
// Created by LENOVO on 11/16/2023.
//
#pragma once
#ifndef CROSSING_ROAD_OBSTACLE_H
#define CROSSING_ROAD_OBSTACLE_H

#include "raylib.h"
#include "Observer.h"
#include "BaseGameObject.h"
#include <list>
#include "raylib-aseprite.h"

class Obstacle : public BaseGameObject {
    int width = 50, height = 30; // Will be updated to sprite later
    bool isMoving; // remove
    int direction; // 1 for right -1 for left . 0 not moving
    std::list<IObserver *> list_observer_;
    Aseprite *sprite;

public:
    Obstacle(double x, double y, int direction) : BaseGameObject(x, y), isMoving(true), direction(direction), sprite(nullptr) {}

    void initObstacle();
    void draw();
    void handleInput();

    bool checkCollision(Rectangle mainCharacter);

    ~Obstacle() {
        delete sprite;
    }
};

#endif //CROSSING_ROAD_OBSTACLE_H
