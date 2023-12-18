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

using namespace std;

class BaseGameObject : public ISubject {
protected:
    int x, y;
    double screenSpeed = 0.1;
    std::list<IObserver *> list_observer_;
    bool isMainCharDead = false;
    bool isGamePause = false;
public:
    BaseGameObject(double x, double y) : x(x), y(y) {};
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

    virtual void updateMainPos(Rectangle mainPosRect) = 0;
    void setMainCharacterDead(bool isDead) {
        isMainCharDead = isDead;
    }
    void pauseGame() {
        isGamePause=!isGamePause;
    }
    void moveDown() {
        y+=48;
    }
};


#endif //CROSSING_ROAD_BASEGAMEOBJECT_H
