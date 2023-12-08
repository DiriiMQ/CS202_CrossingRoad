//
// Created by LENOVO on 11/16/2023.
//
#include "Obstacle.h"
#include "temp.cpp"
#include "../assetsLib/ConfigIO.h"

using namespace std;

void Obstacle::handleInput() {
    UpdateAsepriteTag(&spriteTag);
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        if (!checkCollision())
            y += 48;
    }
}

void Obstacle::draw() {
//    y += screenSpeed;

    Rectangle boxRect{(float) x, (float) y, (float) (width * 1.5), (float) (height * 1.5)};
//    DrawRectangleRec(boxRect, WHITE);

    DrawAsepriteTagPro(spriteTag, boxRect, {(float)0, (float)0}, 0, WHITE);
//    isMoving=true;
    if (isMoving) {
        if (!checkCollision())
        {
            x += direction;
        }
        else {
            cout << "COLLISION with object at position: (" << x << ", " << y << ")" << endl;
            cout << "Main Char position: (" << mainPosRect.x << ", " << mainPosRect.y << ")" << endl;
            BaseGameObject::Notify(Message::COLLISION);
            isMoving = false;
        }
    }
    if((direction == 1 && x > 1366 + 50) || (direction == -1 && x < 0)) { // TODO: Load from config file
        BaseGameObject::Notify(Message::BLOCK_OUT_OF_SCREEN);
    }
}
void Obstacle::initObstacle() {

    vector<string> textureList = BasicConfigInstance::getData(ConfigType::BASIC)["TEXTURES"]["OBSTACLES"];
    vector<string> tagList = BasicConfigInstance::getData(ConfigType::BASIC)["TEXTURES"]["OBSTACLES_TAG"];

    int randIndex = rand() % textureList.size();

    sprite = LoadAseprite(textureList[randIndex].c_str());
    spriteTag = LoadAsepriteTag(sprite, tagList[randIndex].c_str());

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
