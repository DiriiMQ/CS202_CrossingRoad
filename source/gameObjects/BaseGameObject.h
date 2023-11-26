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
    std::list<IObserver *> list_observer_;
    

public:
   BaseGameObject () {};
    BaseGameObject(int x, int y) : x(x), y(y) {};
    virtual void draw() = 0;
    virtual void handleInput() = 0;

    void Attach(IObserver *observer) override {
        list_observer_.push_back(observer);
    }

    void Detach(IObserver *observer) override {
        list_observer_.remove(observer);
    }
    void Notify() override {
        std::list<IObserver *>::iterator iterator = list_observer_.begin();
        while (iterator != list_observer_.end()) {
            (*iterator)->Update(Message::BLOCK_OUT_OF_SCREEN);
            ++iterator;
        }
    }
    virtual bool checkCollision(Vector2 pos,Vector2 size)
    {
        return false;
    }
    virtual void updateMainPos(Rectangle mainPosRect) = 0;
    
};


#endif //CROSSING_ROAD_BASEGAMEOBJECT_H
