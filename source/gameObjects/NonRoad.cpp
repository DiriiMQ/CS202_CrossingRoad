//
// Created by LENOVO on 11/17/2023.
//

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
}

void NonRoad::handleInput() {

    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && (mainChar && mainChar->canMoveUp)) {
        y += stepSize;
    }
    for (Obstacle *obs: staticObs) {
        obs->handleInput();
    }
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
}

void NonRoad::moveY(double offset) {
    y += offset;
    for(Obstacle *obs: staticObs) {
        obs->moveY(offset);
    }
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