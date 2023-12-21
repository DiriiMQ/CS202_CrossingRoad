//
// Created by LENOVO on 11/16/2023.
//
#include "Obstacle.h"
#include "temp.cpp"
#include "assetsLib/ConfigIO.h"

using namespace std;

void Obstacle::handleInput() {
    if (direction != 0)
        UpdateAsepriteTag(&spriteTag);

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        if (!checkCollision()) {
            y += stepSize;
        }
    }
}

void Obstacle::draw() {
//    y += screenSpeed;

    Rectangle boxRect{x,  y, (float) width, (float) height};
    DrawRectangleRec(boxRect, WHITE);

    if (direction != 0)
        DrawAsepriteTagPro(spriteTag, boxRect, {0., 0.}, 0, WHITE);
    else
        DrawAsepritePro(sprite, 0, boxRect, {0., 0.}, 0, WHITE);

    if (isMoving) {
        handleCollision();
        int screenWidth = BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"];
        if ((direction == 1 && x > screenWidth + 100) || (direction == -1 && x < -100)) {
            BaseGameObject::Notify(Message::BLOCK_OUT_OF_SCREEN);
        }
    }
}
void Obstacle::initObstacle() {
    string obstacleField = direction == 0 ? "STATIC_OBSTACLES" : "OBSTACLES";

    vector<string> tagList = BasicConfigInstance::getData(ConfigType::BASIC)["TEXTURES"][obstacleField + "_TAG"];
    int randIndex = 0;

//    sprite = LoadAseprite(textureList[randIndex].c_str());
    sprite = AsepriteInstance::getAseprite(direction == 0 ? AsepriteType::STATIC : AsepriteType::ANIMATED, randIndex);

    string tag = direction != 1 ? tagList[randIndex] : "l2r";

    if (direction != 0)
        spriteTag = LoadAsepriteTag(sprite, tag.c_str());
    width = GetAsepriteWidth(sprite) * 1.5;
    height = GetAsepriteHeight(sprite) * 1.5;
}

void Obstacle::updateMainPos(Rectangle mainPosRect)
{
    this->mainPosRect = mainPosRect;
}

void Obstacle::handleCollision() {
    if (!checkCollision())
    {
        x += direction;
    }
    else {
        cout << "COLLISION with object at position: (" << x << ", " << y << ")" << endl;
        cout << "Main Char position: (" << mainPosRect.x << ", " << mainPosRect.y << ")" << endl;
        BaseGameObject::Notify(Message::COLLISION);
    }
}

bool Obstacle::checkCollision()
{
    
    Rectangle rect1 = {float (x),float (y), (float) width,(float) height};
    return CheckCollisionRecs(rect1,mainPosRect);
}

void Obstacle::setMove(bool move) {
    isMoving = move;
}

int Obstacle::getWidth() const
{
    return width;
}

int Obstacle::getHeight() const
{
    return height;
}
