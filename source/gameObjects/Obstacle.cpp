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

    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && mainChar->canMoveUp) {
        if (!checkCollision()) {
            y += stepSize;
        }
    }
}

void Obstacle::draw() {
//    y += screenSpeed;

    Rectangle boxRect{x,  y, (float) width, (float) height};

    if (direction != 0)
        DrawAsepriteTagPro(spriteTag, boxRect, {0., 0.}, 0, WHITE);
    else
        DrawAsepritePro(sprite, 0, boxRect, {0., 0.}, 0, WHITE);

    handleCollision();
    if (direction == 0) // STATIC OBSTACLES
        handleBlockMove();
    if (isMoving) {
        int screenWidth = BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"];
        if ((direction == 1 && x > screenWidth + 100) || (direction == -1 && x < -100)) {
            BaseGameObject::Notify(Message::BLOCK_OUT_OF_SCREEN);
        }
    }
}
void Obstacle::initObstacle() {
    string obstacleField = direction == 0 ? "STATIC_OBSTACLES" : "OBSTACLES";

    vector<string> tagList = BasicConfigInstance::getData(ConfigType::BASIC)["TEXTURES"][obstacleField + "_TAG"];

    int randIndex = -1;
    if(direction == 0)
        randIndex = weather;

//    sprite = LoadAseprite(textureList[randIndex].c_str());
    sprite = AsepriteInstance::getAseprite(direction == 0 ? AsepriteType::STATIC : AsepriteType::ANIMATED, randIndex);

    string tag = direction != 1 ? tagList[randIndex] : "l2r";

    if (direction != 0)
        spriteTag = LoadAsepriteTag(sprite, tag.c_str());
    width = GetAsepriteWidth(sprite) * 1.5;
    height = GetAsepriteHeight(sprite) * 1.5;
    this->objectIndex = randIndex;
}

void Obstacle::updateMainPos(Rectangle mainPosRect)
{
    this->mainPosRect = mainPosRect;
}

void Obstacle::handleCollision() {
    if (checkCollision() && isMoving) {
        cout << "COLLISION with object at position: (" << x << ", " << y << ")" << endl;
        cout << "Main Char position: (" << mainPosRect.x << ", " << mainPosRect.y << ")" << endl;
        BaseGameObject::Notify(Message::COLLISION);
    }
    else if (isMoving){
        x += direction;
    }
}

void Obstacle::handleBlockMove() {
    if(mainChar) {
        Rectangle blockRect = {float(x), float(y), (float) width, (float) height};
        float blockSize = stepSize * 2;
        mainPosRect = mainChar->returnMainPos();
        Rectangle rectUp = mainPosRect;
        Rectangle rectLeft = mainPosRect;
        Rectangle rectRight = mainPosRect;
        Rectangle rectDown = mainPosRect;

        rectUp.y -= blockSize;
        rectDown.y += blockSize;
        rectLeft.x -= blockSize;
        rectRight.x += blockSize;

        if (CheckCollisionRecs(blockRect, rectUp))
            mainChar->canMoveUp = false;
        else if (CheckCollisionRecs(blockRect, rectLeft))
            mainChar->canMoveLeft = false;
        else if (CheckCollisionRecs(blockRect, rectRight))
            mainChar->canMoveRight = false;
        else if (CheckCollisionRecs(blockRect, rectDown))
            mainChar->canMoveDown = false;
//        else {
//            mainChar->canMoveUp = true;
//            mainChar->canMoveLeft = true;
//            mainChar->canMoveRight = true;
//        }
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

int Obstacle::getWidth() const {
    return width;
}

int Obstacle::getHeight() const {
    return height;
}

json Obstacle::toJson() {
    json saveData = BaseGameObject::toJson();
    saveData["width"] = this->width;
    saveData["height"] = this->height;
    saveData["direction"] = this->direction;
    saveData["objectIndex"] = this->objectIndex;
    saveData["isMoving"] = this->isMoving;

    return saveData;
}

void Obstacle::fromJson(json saveData) {
    BaseGameObject::fromJson(saveData);
    this->width = saveData["width"];
    this->height = saveData["height"];
    this->direction = saveData["direction"];
    this->isMoving = saveData["isMoving"];
    this->objectIndex = saveData["objectIndex"];

    string obstacleField = direction == 0 ? "STATIC_OBSTACLES" : "OBSTACLES";

    vector<string> tagList = BasicConfigInstance::getData(ConfigType::BASIC)["TEXTURES"][obstacleField + "_TAG"];

//    sprite = LoadAseprite(textureList[randIndex].c_str());
    sprite = AsepriteInstance::getAseprite(direction == 0 ? AsepriteType::STATIC : AsepriteType::ANIMATED, objectIndex);

    string tag = direction != 1 ? tagList[objectIndex] : "l2r";

    if (direction != 0)
        spriteTag = LoadAsepriteTag(sprite, tag.c_str());

}

