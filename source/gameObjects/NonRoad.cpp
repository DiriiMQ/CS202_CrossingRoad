//
// Created by LENOVO on 11/17/2023.
//
#include <cstdio> // or #include <stdio.h>
#include "NonRoad.h"

NonRoad::NonRoad(float x, float y, int numStatic, MainChar *mainChar) : BaseGameObject(x, y), mainChar(mainChar) {
    int direction = 0; // static obstacles
    int originX = RandomNumber::getInstance().getRandomNumber(
            0,
            BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"]
    );

    for (int i = 0; i < numStatic; i++) {
        Obstacle *obs = new Obstacle(originX, y, direction, mainChar);
//        obs->Attach(this);
        obs->initObstacle();
        staticObs.push_back(obs);
        originX += (
                RandomNumber::getInstance().getRandomNumber(10, 200) +
                obs->getWidth() * 2
        );
    }
    int randNum = RandomNumber::getInstance().getRandomNumber(0, 1);
    if (randNum) hasAnimal=true;
    else hasAnimal = false;
    if (hasAnimal)
    {
        int randNum1 = RandomNumber::getInstance().getRandomNumber(0, 1);
         if (randNum1) direction = 1;
        else direction = -1;
        nonStaticObs = new Animal(0 /*originX*/, y, 1, mainChar);
        
    }
    
    else
    {
        nonStaticObs=nullptr;
    }

}

void NonRoad::handleInput() {

    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && (mainChar && mainChar->canMoveUp)) {
        y += stepSize;
    }
    for (Obstacle *obs: staticObs) {
        obs->handleInput();
    }
    if (nonStaticObs) nonStaticObs->handleInput();
}

//void NonRoad::setScreenSpeed(double speed) {
//    screenSpeed = speed;
//    for(Obstacle *obs: staticObs) {
//        obs->setScreenSpeed(speed);
//    }
//}

void NonRoad::draw() {
//    y += screenSpeed;

    DrawRectangle(x, y, 1500, (float) stepSize * 2,  Color{205, 223, 108, 255});

    for(Obstacle *obs: staticObs) {
        obs->draw();
    }
    json cfg = BasicConfigInstance::getData(ConfigType::BASIC);

    if(y > (int) cfg["SCREEN"]["SIZE"]["HEIGHT"] + (int) cfg["TEXTURES"]["OUT_SCREEN_OFFSET"]) {
        cout << "UPDATE CALLED!" << endl;
        BaseGameObject::Notify();
    }
    if (nonStaticObs)
    {
         nonStaticObs->draw();
    
        if (isMainCharDead || isGamePause) nonStaticObs->setMove(false);
        else  nonStaticObs->setMove(true);
    }
   
}

void NonRoad::moveY(double offset) {
    y += offset;
    for(Obstacle *obs: staticObs) {
        obs->moveY(offset);
    }
    if (nonStaticObs)
        nonStaticObs->moveY(offset);

}

json NonRoad::toJson() {
    json saveData = BaseGameObject::toJson();
    json staticObsJson;
    for (Obstacle *obs: staticObs) {
        staticObsJson.push_back(obs->toJson());
    }
    saveData["static_obs"] = staticObsJson;
    return saveData;
}

void NonRoad::fromJson(json saveData) {

    BaseGameObject::fromJson(saveData);
    vector<Obstacle*> staticObs;
    for(const auto& staticObsJson: saveData["static_obs"]) {
        Obstacle *obs = new Obstacle;
        obs->fromJson(staticObsJson);
        staticObs.push_back(obs);
    }
    this->staticObs = staticObs;

}

void NonRoad::setMainChar(MainChar *mainChar) {
    this->mainChar = mainChar;
    for(Obstacle *obs: staticObs) {
        obs->setMainChar(mainChar);
    }
}

NonRoad::~NonRoad() {
    for (Obstacle *obs: staticObs) {
        delete obs;
    }
    delete nonStaticObs;
}