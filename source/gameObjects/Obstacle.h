//
// Created by LENOVO on 11/16/2023.
//

#ifndef CROSSING_ROAD_OBSTACLE_H
#define CROSSING_ROAD_OBSTACLE_H

#include "raylib.h"
#include "Observer.h"
#include "BaseGameObject.h"
#include "stuff/RandomNumber.h"
#include <list>
#include "raylib-aseprite.h"

class Obstacle : public BaseGameObject {
    int width = 0, height = 0;
    int direction; // 1 for right -1 for left
    Aseprite sprite;
    AsepriteTag spriteTag;

    std::list<IObserver *> list_observer_;
    Rectangle mainPosRect;
    bool isMoving;

public:
    Obstacle(double x, double y, int direction) : BaseGameObject(x, y), isMoving(true), direction(direction) {}

    void initObstacle();
    void draw();
    void handleInput();

    ~Obstacle() {}
    bool checkCollision();
    //void getPos(Vector2 mainPos,Vector2 mainSize);
    void updateMainPos(Rectangle mainPosRect);
    void setMove(bool move);

    int getWidth() const;
    int getHeight() const;
};

#endif //CROSSING_ROAD_OBSTACLE_H
