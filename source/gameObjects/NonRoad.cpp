//
// Created by LENOVO on 11/17/2023.
//
#include <cstdio> // or #include <stdio.h>
#include "NonRoad.h"

NonRoad::NonRoad(float x, float y, int numStatic, MainChar *mainChar, int weather) : BaseGameObject(x, y), mainChar(mainChar), weather(weather) {
    int randNum = RandomNumber::getInstance().getRandomNumber(0, 1);
    if (randNum) direction = 1;
    else direction = -1;

    int originX = RandomNumber::getInstance().getRandomNumber(
            0,
            BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"]
    );
    hasAnimal = RandomNumber::getInstance().getRandomNumber(0, 1);

    for (int i = 0; i < numStatic; i++) {

        Obstacle *obs;
        if (hasAnimal)
            obs = new Animal(originX, y, direction, mainChar);
        else
            obs = new Obstacle(originX, y, 0, mainChar, weather);
        obs->Attach(this);
        obs->initObstacle();
        staticObs.push_back(obs);
        originX += (
                RandomNumber::getInstance().getRandomNumber(10, 200) +
                obs->getWidth() * 2
        );
    }
//    int randNum = RandomNumber::getInstance().getRandomNumber(0, 1);
//    if (randNum) hasAnimal=true;
//    else hasAnimal = false;
//    if (hasAnimal)
//    {
//        int randNum1 = RandomNumber::getInstance().getRandomNumber(0, 1);
//         if (randNum1) direction = 1;
//        else direction = -1;
//        nonStaticObs = new Animal(0 /*originX*/, y, direction, mainChar);
//
//    }
//
//    else
//    {
//        nonStaticObs=nullptr;
//    }

}

void NonRoad::handleInput() {

    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && (mainChar && mainChar->canMoveUp)) {
        y += stepSize;
    }
    for (Obstacle *obs: staticObs) {

        obs->handleInput();
    }
//    if (nonStaticObs) nonStaticObs->handleInput();
}

//void NonRoad::setScreenSpeed(double speed) {
//    screenSpeed = speed;
//    for(Obstacle *obs: staticObs) {
//        obs->setScreenSpeed(speed);
//    }
//}


void NonRoad::handleBlockOutOfScreen() {
    // double newPositionX;
    // if (direction == -1)
    //     newPositionX = 1336 + 50;
    // else
    //     newPositionX = obstacles.back()->getX() - 1366 - 50;

    // Obstacle *obs = new Obstacle( newPositionX, y, direction);
    // obs->Attach(this);
    // obs->initObstacle();
    // obstacles.push_back(obs);
    // obstacles.erase(obstacles.begin());

    int screenW = BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"];
    int newX = staticObs[0]->getX();

    if (direction == -1)
        newX = max(
                newX + RandomNumber::getInstance().getRandomNumber(10, 200) + staticObs[0]->getWidth() * 2,
                screenW + 50
        );
    else
        newX = min(
                newX - (RandomNumber::getInstance().getRandomNumber(10, 200) + staticObs[0]->getWidth() * 2),
                -50
        );

    Obstacle *obs = new Animal(newX, y, direction, mainChar);
    obs->Attach(this);
    obs->initObstacle();
    staticObs.insert(staticObs.begin(), obs);
    staticObs.pop_back();
}


void NonRoad::updateMessage(const Message message) {
    if(message == Message::BLOCK_OUT_OF_SCREEN)
        this->handleBlockOutOfScreen();
}

void NonRoad::draw() {
//    y += screenSpeed;
    Color grassColor;
    if(weather == Weather::SPRING)
        grassColor = Color{110, 220, 150, 255};
    else if(weather == Weather::SUMMER)
        grassColor = Color{205, 223, 108, 255};
    else if(weather == Weather::FALL)
        grassColor = Color{166, 163, 84, 255};
    else if(weather == Weather::WINTER)
        grassColor = Color{214, 214, 214, 255};

    DrawRectangle(x, y, 1500, (float) stepSize * 2,  grassColor);

    for(Obstacle *obs: staticObs) {
        if(isMainCharDead || isGamePause)
            obs->setMove(false);
        obs->draw();
    }
    json cfg = BasicConfigInstance::getData(ConfigType::BASIC);

    if(y > (int) cfg["SCREEN"]["SIZE"]["HEIGHT"] + (int) cfg["TEXTURES"]["OUT_SCREEN_OFFSET"]) {
        cout << "UPDATE CALLED!" << endl;
        BaseGameObject::Notify();
    }
//    if (nonStaticObs)
//    {
//         nonStaticObs->draw();
//
//        if (isMainCharDead || isGamePause) nonStaticObs->setMove(false);
//        else  nonStaticObs->setMove(true);
//    }
   
}

void NonRoad::moveY(double offset) {
    y += offset;
    for(Obstacle *obs: staticObs) {
        obs->moveY(offset);
    }
//    if (nonStaticObs)
//        nonStaticObs->moveY(offset);

}

json NonRoad::toJson() {
    json saveData = BaseGameObject::toJson();
    json staticObsJson;
    for (Obstacle *obs: staticObs) {
        staticObsJson.push_back(obs->toJson());
    }
    saveData["static_obs"] = staticObsJson;
    saveData["hasAnimal"] = hasAnimal;
    saveData["weather"] = weather;
    return saveData;
}

void NonRoad::fromJson(json saveData) {

    BaseGameObject::fromJson(saveData);
    vector<Obstacle*> staticObs;
    hasAnimal = saveData["hasAnimal"];
    weather = saveData["weather"];
    for(const auto& staticObsJson: saveData["static_obs"]) {

        Obstacle *obs ;
        if (hasAnimal)
            obs = new Animal;
        else
            obs = new Obstacle;

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
//    delete nonStaticObs;
}