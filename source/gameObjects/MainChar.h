#ifndef CROSSING_ROAD_MAINCHAR_H
#define CROSSING_ROAD_MAINCHAR_H
#include "BaseGameObject.h"
#include "Observer.h"
#include "Obstacle.h"
#include <vector>
#include <iostream>
#include "assetsLib/ConfigIO.h"
#include "raylib-aseprite.h"

using namespace std;
//class mainChar : public Obstacle
class MainChar : public BaseGameObject
{
protected: 
    int stepSizeX=25;
    int stepSizeY=24;
    bool isDead=false;
    float width = 40;
    float height=40;
    Aseprite sprite;
    AsepriteTag spriteTag;

public:
    MainChar() : BaseGameObject(722,626) {
        sprite = LoadAseprite("../assets/george.aseprite");
        spriteTag = LoadAsepriteTag(sprite, "Walk-Up");

    }
    void draw() override;
    void handleInput() override;


    void updateMainPos(Rectangle mainPosRec) override {};
    Rectangle returnMainPos();
    void setDead() { isDead = true; };
    bool getDead() { return isDead; }
    ~MainChar();
};

#endif //CROSSING_ROAD_MAINCHAR_H