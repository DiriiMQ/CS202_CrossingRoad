//
// Created by LENOVO on 11/17/2023.
//

#include "NonRoad.h"

NonRoad::NonRoad(int x, int y, int numStatic) : BaseGameObject(x, y) {
    int direction = 0; // static obstacles
    int originX = RandomNumber::getInstance().getRandomNumber(
            0,
            BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"]
    );

    for (int i = 0; i < numStatic; i++) {
        Obstacle *obs = new Obstacle(originX, y, direction);
//        obs->Attach(this);
        obs->initObstacle();
        staticObs.push_back(obs);
        originX += (
                RandomNumber::getInstance().getRandomNumber(10, 200) +
                obs->getWidth() * 2
        );
    }
}

void NonRoad::handleInput() {

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        y += stepSize;
    }
    for (Obstacle *obs: staticObs) {
        obs->handleInput();
    }
}

void NonRoad::draw() {
//    y += screenSpeed;


    DrawRectangle(x, y, 1500, 50,  Color{205, 223, 108, 255});

    for(Obstacle *obs: staticObs) {
        obs->draw();
    }
    json cfg = BasicConfigInstance::getData(ConfigType::BASIC);

    if(y > (int) cfg["SCREEN"]["SIZE"]["HEIGHT"] + (int) cfg["TEXTURES"]["OUT_SCREEN_OFFSET"]) {
        cout << "UPDATE CALLED!" << endl;
        BaseGameObject::Notify();
    }


}