//
// Created by LENOVO on 12/18/2023.
//

#ifndef CROSSING_ROAD_BOAT_H
#define CROSSING_ROAD_BOAT_H
#include "BaseGameObject.h"
#include "raylib-aseprite.h"
#include "assetsLib/AsepriteIO.h"
#include "assetsLib/ConfigIO.h"
#include "MainChar.h"

class Boat : public BaseGameObject {
    int width, height;
    int direction;
    Aseprite sprite;
    bool isMoving = true;
    Rectangle mainPosRect;
    MainChar *mainChar;

public:
    Boat(float x, float y, int direction, MainChar *mainChar);
    void draw() override;
    void handleInput() override;
    void handleCollision();
    void setMove(bool move);
    virtual void updateMainPos(Rectangle mainPosRect);


    float getWidth();
    bool checkCollision();

    json toJson() override;
    void fromJson(json saveData) override

};


#endif //CROSSING_ROAD_BOAT_H
