#include "Animal.h"
#include "temp.cpp"
#include "assetsLib/ConfigIO.h"


void Animal::handleInput() {
    Rectangle blockRect = {float(x), float(y), (float) width, (float) height};
    float blockSize = stepSize ;
    Rectangle rectUp = mainPosRect;
    rectUp.y -= blockSize;
    UpdateAsepriteTag(&spriteTag);
    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && mainChar->canMoveUp) {
        if (!CheckCollisionRecs(blockRect, rectUp)) {
            y += stepSize;
        }
    }
}
void Animal::handleCollision() {
    if (checkCollision() && isMoving) {
        cout << "COLLISION with object at position: (" << x << ", " << y << ")" << endl;
        cout << "Main Char position: (" << mainPosRect.x << ", " << mainPosRect.y << ")" << endl;
        BaseGameObject::Notify(Message::COLLISION);
        mainChar->moveX(direction);
    }
    else if (isMoving){
        x += direction;
    }
}
void Animal::draw() { 
    handleCollision();
    handleBlockMove();
    Rectangle boxRect{x,  y, (float) width, (float) height};
//    DrawAsepritePro(sprite, 0, boxRect, {0., 0.}, 0, WHITE);
    DrawAsepriteTagPro(spriteTag, boxRect, {0, 0}, 0, WHITE);
    
}

void Animal::handleBlockMove() {
    if(mainChar) {
        Rectangle blockRect = {float(x), float(y), (float) width, (float) height};
        float blockSize = stepSize;
        mainPosRect = mainChar->returnMainPos();
        Rectangle rectUp = mainPosRect;
        Rectangle rectLeft = mainPosRect;
        Rectangle rectRight = mainPosRect;

        rectUp.y -= blockSize;
        rectLeft.x -= blockSize;
        rectRight.x += blockSize;
        if (CheckCollisionRecs(blockRect, rectUp))
            mainChar->canMoveUp = false;
        else if (CheckCollisionRecs(blockRect, rectLeft))
            {
                mainChar->canMoveLeft = false;
                if (mainChar->canMoveRight)
                    mainChar->moveX(direction);
            }
            
        else if (CheckCollisionRecs(blockRect, rectRight))
            {
                mainChar->canMoveRight = false;
                if (mainChar->canMoveLeft)
                    mainChar->moveX(direction);
            }
//        else {
//            mainChar->canMoveUp = true;
//            mainChar->canMoveLeft = true;
//            mainChar->canMoveRight = true;
//        }
    }
}