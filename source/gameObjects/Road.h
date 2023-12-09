//
// Created by LENOVO on 11/16/2023.
//

#ifndef CROSSING_ROAD_ROAD_H
#define CROSSING_ROAD_ROAD_H
#include "BaseGameObject.h"
#include "Observer.h"
#include "Obstacle.h"
#include <vector>
#include <iostream>
#include "screen/Position.h"
#include <algorithm>
#include "TrafficLight.h"
#include "stuff/RandomNumber.h"
#include "assetsLib/ConfigIO.h"

using namespace std;

class Road : public BaseGameObject, public IObserver {
private:
    int stepSize = 48;
    vector<Obstacle*> obstacles;
    Aseprite roadSprite;
    int direction = 1;
    int numObstacles;
    float speed = 1;
    bool hasLight;
    int randomPercentage=25;
    TrafficLight* light;
   // bool isMainAlive=true;
    
public:


    Road(int x, int y, int numObstacles = 5);
    ~Road() override;
    void draw() override;
    void handleInput() override;

    void handleBlockOutOfScreen();
    void handleCollision();

    void updateMessage(const Message message) override;
    void updateMainPos(Rectangle mainPosRect) override;
    void randomLight();
    void lightHandle();
};


#endif //CROSSING_ROAD_ROAD_H
