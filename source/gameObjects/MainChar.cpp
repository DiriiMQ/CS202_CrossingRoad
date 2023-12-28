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
    DrawAsepriteTagPro(spriteTag, rect, { 0.0, 0.0 }, 0, WHITE);


}
void MainChar::handleInput() {
    double screenWidth = BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"];
    double screenHeight = BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["HEIGHT"];
    if (y < 0. || y > screenHeight) isDead = true;

    UpdateAsepriteTag(&spriteTag);
    if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && canMoveLeft) {
        if (eventTriggered(0.15)) {
            x = max(stepSizeX, x - stepSizeX);
            spriteTag = LoadAsepriteTag(sprite, "Walk-Left");
        }
    }
    else if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && canMoveRight)
    {
        if (eventTriggered(0.15)) {
            x = min(screenWidth - stepSizeX, x + stepSizeX);

            spriteTag = LoadAsepriteTag(sprite, "Walk-Right");
        }
    }
    else if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) && canMoveUp) {
        if (eventTriggered(0.15)) {
            y -= stepSizeY;
            spriteTag = LoadAsepriteTag(sprite, "Walk-Up");
        }
    }

    canMoveUp = true;
    canMoveRight = true;
    canMoveLeft = true;
}
Rectangle MainChar::returnMainPos() {
    Rectangle rect1 = { static_cast<float>(x),static_cast<float>(y), width, height};
    return rect1;
}


MainChar::~MainChar() {
    UnloadAseprite(this->sprite);
}
