#ifndef CROSSING_ROAD_MAINCHAR_H
#define CROSSING_ROAD_MAINCHAR_H
#include "BaseGameObject.h"
#include "Observer.h"
#include "Obstacle.h"
#include <vector>
#include <iostream>
#include "assetsLib/ConfigIO.h"

using namespace std;
//class mainChar : public Obstacle
class MainChar : public BaseGameObject
{
protected: 
    int stepSize=25;
    bool isDead=false;
public:
    MainChar() : BaseGameObject(722,722) {}
    void draw() override;
    void handleInput() override;
    void Notify() override {
        std::list<IObserver *>::iterator iterator = list_observer_.begin();
        while (iterator != list_observer_.end()) {
            (*iterator)->Update(Message::COLLISION);
            ++iterator;
        }
    }
    bool checkCollision(Vector2 pos,Vector2 size) override {
        return false;
    }
    Vector2 getPos();
    void updateMainPos(Rectangle mainPosRec) override {};
    Rectangle returnMainPos();
    
};

#endif //CROSSING_ROAD_MAINCHAR_H