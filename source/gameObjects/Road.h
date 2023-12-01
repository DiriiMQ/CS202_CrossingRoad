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

using namespace std;

class Road : public BaseGameObject, public IObserver {
private:
    int stepSize = 48;
    vector<Obstacle*> obstacles;
    //Aseprite roadSprite = LoadAseprite("assets/1_lane.aseprite");
    int direction = 1;

public:

    Road(double x, double y, int numObstacles = 5);

    Road(int x, int y, int numObstacles = 5);
    ~Road() override;
    void draw() override;
    void handleInput() override;

    void updateMessage(const Message message) override;
    void updateMainPos(Rectangle mainPosRect) override;
};


#endif //CROSSING_ROAD_ROAD_H
