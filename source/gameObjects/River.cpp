//
// Created by LENOVO on 11/30/2023.
//

#include "River.h"

River::River(float x, float y, int num_boats, MainChar *mainChar) : BaseGameObject(x, y), mainChar(mainChar) {
    int randNum = RandomNumber::getInstance().getRandomNumber(0, 1);

    if (randNum) direction = 1;
    else direction = -1;

    int originX = RandomNumber::getInstance().getRandomNumber(
        0,
        BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"]
    );

    for (int i = 0; i < num_boats; i++) {
        Boat *boat = new Boat(originX, y, direction, mainChar);

        boat->Attach(this);
        boats.push_back(boat);
        originX += direction * (
            RandomNumber::getInstance().getRandomNumber(10, 200) +
            boat->getWidth() * 2
        );
    }
}

void River::handleInput() {

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        y += stepSize;
    }
    for (Boat *boat: boats) {
        boat->handleInput();
    }
}

void River::draw() {
//    y += screenSpeed;

    DrawRectangle(x, y, 1500, (float) stepSize * 2, Color{134, 180, 188, 255});
    for(Boat *boat: boats) {
        if(isMainCharDead || isGamePause)
            boat->setMove(false);
        else
            boat->setMove(true);
        boat->draw();
    }

    json cfg = BasicConfigInstance::getData(ConfigType::BASIC);

    if(y > (int) cfg["SCREEN"]["SIZE"]["HEIGHT"] + (int) cfg["TEXTURES"]["OUT_SCREEN_OFFSET"]) {
        BaseGameObject::Notify();
    }
}

void River::updateMainPos(Rectangle mainPosRect) {
    for (Boat *boat: boats) {
        boat->updateMainPos(mainPosRect);
    }
}

void River::handleBlockOutOfScreen() {
    float screenW = BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"];
    float newX = boats[0]->getX();


    if (direction == -1)
        newX = max(
                newX + RandomNumber::getInstance().getRandomNumber(10, 200) + boats[0]->getWidth() * 2,
                screenW + 50
        );
    else
        newX = min(
                newX - (RandomNumber::getInstance().getRandomNumber(10, 200) + boats[0]->getWidth() * 2),
                (float) -50
        );

    Boat *boat = new Boat(newX, y, direction, mainChar);
    boat->Attach(this);
    boats.insert(boats.begin(), boat);
    boats.pop_back();
}

void River::updateMessage(const Message message) {
    if (message == Message::BLOCK_OUT_OF_SCREEN) {
        handleBlockOutOfScreen();
    }
}

void River::moveY(double offset) {
    y += offset;
    for(Boat *boat: boats) {
        boat->moveY(offset);
    }
}
