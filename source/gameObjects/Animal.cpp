#include "Animal.h"
#include "temp.cpp"
#include "assetsLib/ConfigIO.h"


void Animal::handleInput() {

    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && mainChar->canMoveUp) {
        if (!checkCollision()) {
            y += stepSize;
        }
    }
}

void Animal::draw() { 
    handleCollision();
    handleBlockMove();
    Rectangle boxRect{x,  y, (float) width, (float) height};
    DrawAsepritePro(sprite, 0, boxRect, {0., 0.}, 0, WHITE);

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