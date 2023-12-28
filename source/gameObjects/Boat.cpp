//
// Created by LENOVO on 12/18/2023.
//

#include "Boat.h"

Boat::Boat(float x, float y, int direction, MainChar *mainChar): BaseGameObject(x, y), direction(direction), mainChar(mainChar) {
    int index = 0;
    sprite = AsepriteInstance::getAseprite(AsepriteType::BOAT, index);

    width = GetAsepriteWidth(sprite) * 4;

    height = GetAsepriteHeight(sprite) * 4;
}

void Boat::setMove(bool move) {
    isMoving = move;
}


void Boat::handleInput() {

    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && mainChar->canMoveUp) {
        y += stepSize;
    }
}

void Boat::updateMainPos(Rectangle mainPosRect)
{
    this->mainPosRect = mainPosRect;
}

void Boat::draw() {
    Rectangle boxRect{x,  y, (float) width, (float) height};
    DrawRectangleRec(boxRect, WHITE);

    DrawAsepritePro(sprite, 0, boxRect, {0., 0.}, 0, WHITE);

//    x += direction;
    if (isMoving) {
        x += direction;
        this->handleCollision();
        int screenWidth = BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"];
        if ((direction == 1 && x > screenWidth + width + 50) || (direction == -1 && x < -width + 50)) {
            BaseGameObject::Notify(Message::BLOCK_OUT_OF_SCREEN);
        }
    }
}

void Boat::handleCollision() {
    if (checkCollision() && mainChar) {
        mainChar->moveX(direction);
    }
}

bool Boat::checkCollision() {
    return CheckCollisionRecs(mainPosRect, Rectangle{x, y, (float) width, (float) height});
}

float Boat::getWidth() {
    return width;
}