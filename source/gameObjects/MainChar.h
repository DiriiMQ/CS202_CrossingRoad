#ifndef CROSSING_ROAD_MAINCHAR_H
#define CROSSING_ROAD_MAINCHAR_H
#include "BaseGameObject.h"
#include "Observer.h"
#include "Obstacle.h"
#include <vector>
#include <iostream>
#include "assetsLib/ConfigIO.h"

using namespace std;
//class mainChar : public Obstacle
class MainChar : public BaseGameObject
{
protected: 
    int stepSizeX=25;
    int stepSizeY=24;
    bool isDead=false;
    float width = 25;
    float height=40;

public:
    MainChar() : BaseGameObject(722,626) {}
    void draw() override;
    void handleInput() override;

    Vector2 getPos();
    void updateMainPos(Rectangle mainPosRec) override {};
    Rectangle returnMainPos();
    void setDead() { isDead = true; };
    bool getDead() { return isDead; }
};

#endif //CROSSING_ROAD_MAINCHAR_H