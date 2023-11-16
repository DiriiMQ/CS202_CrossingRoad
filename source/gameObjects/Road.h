//
// Created by LENOVO on 11/16/2023.
//

#ifndef CROSSING_ROAD_ROAD_H
#define CROSSING_ROAD_ROAD_H
#include "Obstacle.h"
#include <vector>
#include <iostream>

using namespace std;

class Road {
private:
    int x, y;
    vector<Obstacle*> obstacles;
public:

    Road(int x, int y, int numObstacles = 5);
    ~Road();
    void draw();
    void handleInput();

};


#endif //CROSSING_ROAD_ROAD_H
