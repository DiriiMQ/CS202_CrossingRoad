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
    int direction; // 1 for right -1 for left
    std::list<IObserver *> list_observer_;
    //Vector2 mainPos;
   // Vector2 mainSize=(Vector2) {50,50};
    Rectangle mainPosRect;
    bool isMoving;
public:
    Obstacle(double x, double y, int direction) : BaseGameObject(x, y), isMoving(true), direction(direction) {}

    void initObstacle();
    void draw();
    void handleInput();

//    ~Obstacle() {
//        delete sprite;
//    }
    bool checkCollision();
    //void getPos(Vector2 mainPos,Vector2 mainSize);
    void updateMainPos(Rectangle mainPosRect);
    void setMove(bool move) {
        isMoving = move;
    }
   
};

#endif //CROSSING_ROAD_OBSTACLE_H
