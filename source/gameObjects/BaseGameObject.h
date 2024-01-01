//
// Created by LENOVO on 11/17/2023.
//

#ifndef CROSSING_ROAD_BASEGAMEOBJECT_H
#define CROSSING_ROAD_BASEGAMEOBJECT_H
#include "raylib.h"
#include "Observer.h"
#include <list>
#include "Message.h"
#include <iostream>
#include "screen/Position.h"
#include "assetsLib/ConfigIO.h"

using namespace std;

class BaseGameObject : public ISubject {
protected:
    float x, y;
//    double screenSpeed = 0.3;
    std::list<IObserver *> list_observer_;
    bool isMainCharDead = false;
    bool isGamePause = false;
    double stepSize;

public:
    BaseGameObject(float x, float y) : x(x), y(y) {
        stepSize = (double) BasicConfigInstance::getData(ConfigType::BASIC)["GAME"]["STEP_SIZE"] / 2.0;
    };
    BaseGameObject () {};
    virtual void draw() = 0;
    virtual void handleInput() = 0;

    void Attach(IObserver *observer) override {
        list_observer_.push_back(observer);
    }

    void Detach(IObserver *observer) override {
        list_observer_.remove(observer);
    }
    void Notify(Message message=Message::BLOCK_OUT_OF_SCREEN) override {
        std::list<IObserver *>::iterator iterator = list_observer_.begin();
        while (iterator != list_observer_.end()) {
            (*iterator)->updateMessage(message);
            ++iterator;
        }
    }

    double getY() {
        return y;
    }

    double getX() {
        return x;
    }

    virtual void moveY(double offset) {
        y += offset;
    }

    virtual void updateMainPos(Rectangle mainPosRect) = 0;
    void setMainCharacterDead(bool isDead) {
        isMainCharDead = isDead;
    }
    void pauseGame() {
        isGamePause=!isGamePause;
    }

    virtual json toJson() {
        json saveData;
        saveData["x"] = x;
        saveData["y"] = y;
        saveData["isMainCharDead"] = isMainCharDead;
        saveData["isGamePause"] = isGamePause;
        return saveData;
    };
    virtual void fromJson(json saveData) {
        this->x = saveData["x"];
        this->y = saveData["y"];
        this->isMainCharDead = saveData["isMainCharDead"];
        this->isGamePause = saveData["isGamePause"];
    };

};


#endif //CROSSING_ROAD_BASEGAMEOBJECT_H
