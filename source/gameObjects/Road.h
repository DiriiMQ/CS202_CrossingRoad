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

using namespace std;

class Road : public BaseGameObject, public IObserver {
private:
    int stepSize = 48;
    vector<Obstacle*> obstacles;
public:

    Road(int x, int y, int numObstacles = 5);
    ~Road();
    void draw() override;
    void handleInput() override;

    void Update(const Message message);

};


#endif //CROSSING_ROAD_ROAD_H
