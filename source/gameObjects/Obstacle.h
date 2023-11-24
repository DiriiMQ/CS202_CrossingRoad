//
// Created by LENOVO on 11/16/2023.
//

#ifndef CROSSING_ROAD_OBSTACLE_H
#define CROSSING_ROAD_OBSTACLE_H
#include "raylib.h"
#include "Observer.h"
#include <list>

class Obstacle : public ISubject {
    int x, y;
    int width = 50, height = 30; // Will be updated to sprite later
    bool isMoving=true;
    int direction; // 1 for right -1 for left
    std::list<IObserver *> list_observer_;
    Vector2 mainPos;
    Vector2 mainSize=(Vector2) {50,50};

public:
    Obstacle(int x, int y, int direction) : x(x), y(y), isMoving(true), direction(direction) {}

    void draw();
    void handleInput();
    void update();

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
    bool checkCollision(Vector2 mainPos,Vector2 mainSize);
    void getPos(Vector2 mainPos,Vector2 mainSize);
   
};


#endif //CROSSING_ROAD_OBSTACLE_H
