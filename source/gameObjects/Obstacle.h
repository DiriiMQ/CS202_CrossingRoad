//
// Created by LENOVO on 11/16/2023.
//

#ifndef CROSSING_ROAD_OBSTACLE_H
#define CROSSING_ROAD_OBSTACLE_H

#include "raylib.h"
#include "Observer.h"
#include "BaseGameObject.h"
#include "utils/RandomNumber.h"
#include <list>
#include "raylib-aseprite.h"
#include "assetsLib/AsepriteIO.h"
#include "MainChar.h"

class Obstacle : public BaseGameObject {
protected:
    int width = 0, height = 0;
    int direction; // 1 for right -1 for left
    Aseprite sprite;
    AsepriteTag spriteTag;

    std::list<IObserver *> list_observer_;
    Rectangle mainPosRect;
    bool isMoving;
    MainChar *mainChar;

public:
    Obstacle(float x, float y, int direction, MainChar *mainChar)
        : BaseGameObject(x, y), isMoving(true), direction(direction), mainChar(mainChar) {}

    void initObstacle();
    void draw();
    void handleInput() override;
    virtual void handleCollision();
    virtual void handleBlockMove();
    bool checkCollision();

    //void getPos(Vector2 mainPos,Vector2 mainSize);
    void updateMainPos(Rectangle mainPosRect);
    void setMove(bool move);

    ~Obstacle() {}

    int getWidth() const;
    int getHeight() const;
};

#endif //CROSSING_ROAD_OBSTACLE_H
