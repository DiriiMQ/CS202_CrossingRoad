//
// Created by LENOVO on 11/16/2023.
//

#include "Obstacle.h"
using namespace std;

void Obstacle::handleInput() {
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        if (!checkCollision())
        y += 48;
    }
}

void Obstacle::draw() {
    DrawRectangle(x, y, width, height, RED);
    isMoving=true;
    if (isMoving) {
        if (!checkCollision())
        {
            x += direction;
        }
        else isMoving=false;
    }
    if(x > 1366 + 50) { // TODO: Load from config file
        Notify();
    }
}
void Obstacle::updateMainPos(Rectangle mainPosRect) 
{
    this->mainPosRect=mainPosRect;
}

bool Obstacle::checkCollision()
{
    
    //return (((this->x+50>=mainPos.x)&&(this->x+50<=mainPos.x+50))&& ((this->y+30>mainPos.y)&&(this->y+30<mainPos.y+50)));
    Rectangle rect1 = {float (x),float (y),50,30};
    return CheckCollisionRecs(rect1,mainPosRect);
}