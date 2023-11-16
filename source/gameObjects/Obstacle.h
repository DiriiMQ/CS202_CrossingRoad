//
// Created by LENOVO on 11/16/2023.
//

#ifndef CROSSING_ROAD_OBSTACLE_H
#define CROSSING_ROAD_OBSTACLE_H
#include "raylib.h"

class Obstacle{
    int x, y;
    int width = 50, height = 30; // Will be updated to sprite later
    bool isMoving;
    int direction; // 1 for right -1 for left

public:
    Obstacle(int x, int y, int direction) : x(x), y(y), isMoving(true), direction(direction) {}

    void draw();
    void handleInput();
    void update();

};


#endif //CROSSING_ROAD_OBSTACLE_H
