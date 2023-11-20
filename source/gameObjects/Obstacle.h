//
// Created by LENOVO on 11/16/2023.
//

#ifndef CROSSING_ROAD_OBSTACLE_H
#define CROSSING_ROAD_OBSTACLE_H
#include "raylib.h"
#include "Observer.h"
#include "BaseGameObject.h"
#include <list>
#include "_raygui.h"
//#include "raylib-aseprite.h"
//#include "cute_aseprite.h"

class Obstacle : public ISubject, public BaseGameObject {
    int width = 50, height = 30; // Will be updated to sprite later
    bool isMoving; // remove
    int direction; // 1 for right -1 for left . 0 not moving
    std::list<IObserver *> list_observer_;

public:
    Obstacle(int x, int y, int direction) : BaseGameObject(x, y), isMoving(true), direction(direction) {}

    void draw();
    void handleInput();

    bool checkCollision(Rectangle mainCharacter);

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
};


#endif //CROSSING_ROAD_OBSTACLE_H
