#include "MainChar.h"
double lastUpdate=0;

bool eventTriggered(double interval)
{
    double currentTime=GetTime();
    if (currentTime-lastUpdate >=interval)
    {
        lastUpdate=currentTime;
        return true;
    }
    return false;
}
void MainChar::draw()
{
//    y += screenSpeed;
    Rectangle  rect{(float)x, (float)y, width, height};
    DrawAsepriteTagPro(spriteTag, rect, { 0.0, 0.0}, 0, WHITE);


}
void MainChar::handleInput()
{
    UpdateAsepriteTag(&spriteTag);
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        if (eventTriggered(0.15)) {
            x -= stepSizeX;
            spriteTag = LoadAsepriteTag(sprite, "Walk-Left");
        }
    }
    else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        if (eventTriggered(0.15)) {
            x += stepSizeX;
            spriteTag = LoadAsepriteTag(sprite, "Walk-Right");
        }
    }
    else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        if (eventTriggered(0.15)) {
            y = 626;
            spriteTag = LoadAsepriteTag(sprite, "Walk-Up");
        }
    }
}
Rectangle MainChar::returnMainPos()
{
    Rectangle rect1 = { static_cast<float>(x),static_cast<float>(y), width, height};
    return rect1;
}


MainChar::~MainChar() {
    UnloadAseprite(this->sprite);
}
