//
// Created by LENOVO on 11/16/2023.
//
#include "Obstacle.h"
#include "temp.cpp"

using namespace std;

void Obstacle::handleInput() {

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        if (!checkCollision())
            y += 48;
    }
}

void Obstacle::draw() {
//    y += screenSpeed;

    Rectangle boxRect{(float) x, (float) y, (float) (width * 1.5), (float) (height * 1.5)};
//    DrawRectangleRec(boxRect, WHITE);

    DrawAsepritePro(sprite, 5, boxRect, {(float)0, (float)0}, 0, WHITE);
//    isMoving=true;
    if (isMoving) {
        if (!checkCollision())
        {
            x += direction;
        }
        else {
            BaseGameObject::Notify(Message::COLLISION);
            isMoving = false;
        }
    }
    if(x > 1366 + 50) { // TODO: Load from config file
        BaseGameObject::Notify(Message::BLOCK_OUT_OF_SCREEN);
    }
}
void Obstacle::initObstacle() {
    sprite = LoadAseprite("../assets/vehicle/NoRoofCar.aseprite");
    width = GetAsepriteWidth(sprite);
    height = GetAsepriteHeight(sprite);
}

void Obstacle::updateMainPos(Rectangle mainPosRect)
{
    this->mainPosRect=mainPosRect;
}

bool Obstacle::checkCollision()
{
    
    //return (((this->x+50>=mainPos.x)&&(this->x+50<=mainPos.x+50))&& ((this->y+30>mainPos.y)&&(this->y+30<mainPos.y+50)));
    Rectangle rect1 = {float (x),float (y), (float) width,(float) height};
    return CheckCollisionRecs(rect1,mainPosRect);
}
