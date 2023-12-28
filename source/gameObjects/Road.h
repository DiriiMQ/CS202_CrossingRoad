//
// Created by LENOVO on 11/16/2023.
//

#ifndef CROSSING_ROAD_ROAD_H
#define CROSSING_ROAD_ROAD_H
#include "BaseGameObject.h"
#include "Observer.h"
#include "Obstacle.h"
#include <vector>
#include "TrafficLight.h"
#include "MainChar.h"

using namespace std;

class Road : public BaseGameObject, public IObserver {
private:
    vector<Obstacle*> obstacles;
    Aseprite roadSprite;
    int direction = 1;
    int numObstacles;
    float speed = 1;
    bool hasLight;
    int randomPercentage = 50;
    TrafficLight* light;
    MainChar *mainChar;

public:
    Road(float x, float y, int numObstacles = 5, MainChar *mainChar = nullptr);
    ~Road() override;
    void draw() override;
    void handleInput() override;

    void handleBlockOutOfScreen();
    void handleCollision();

    void updateMessage(const Message message) override;
    void updateMainPos(Rectangle mainPosRect) override;
    void randomLight();
    void lightHandle();
//    void setScreenSpeed(double speed) override;
    void moveY(double offset) override;
};


#endif //CROSSING_ROAD_ROAD_H
