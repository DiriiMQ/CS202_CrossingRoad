#ifndef CROSSING_ROAD_MAINCHAR_H
#define CROSSING_ROAD_MAINCHAR_H
#include "BaseGameObject.h"
#include "Observer.h"
#include <vector>
#include <iostream>
#include "assetsLib/ConfigIO.h"
#include "raylib-aseprite.h"

using namespace std;
//class mainChar : public Obstacle
class MainChar : public BaseGameObject
{
protected: 
    double stepSizeX;
    double stepSizeY;
    bool isDead = false;
    float width = 40;
    float height = 40;
    Aseprite sprite;
    AsepriteTag spriteTag;

public:

    bool canMoveLeft = true;
    bool canMoveRight = true;
    bool canMoveUp = true;
    bool canMoveDown = true;

    MainChar() : BaseGameObject(722.0,658.0) {
        sprite = LoadAseprite("../assets/george.aseprite");
        spriteTag = LoadAsepriteTag(sprite, "Walk-Up");
        stepSizeY = (double) BasicConfigInstance::getData(ConfigType::BASIC)["GAME"]["STEP_SIZE"] / 2;
        stepSizeX = stepSizeY;
    }
    void draw() override;
    void handleInput() override;


    void updateMainPos(Rectangle mainPosRec) override {};
    Rectangle returnMainPos();
    void setDead() { isDead = true; };
    bool getDead() { return isDead; }

    ~MainChar();
    void resetMainChar() {
        x = 722;
        y = 658;
    }

    void mainCharRevive() {
        this->isDead = false;
    }

    void moveX(double offset) {
        x += offset;
    };

    json toJson() override;
    void fromJson(json saveData) override;
};

#endif //CROSSING_ROAD_MAINCHAR_H