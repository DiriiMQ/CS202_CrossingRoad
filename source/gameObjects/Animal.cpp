#include "Animal.h"
#include "temp.cpp"
#include "assetsLib/ConfigIO.h"


void Animal::draw() { 
    handleCollision();
    handleBlockMove();
    DrawRectangle (int (x), int (y), int (width), int (height), RED);
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
                mainChar->canMoveLeft = false;
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