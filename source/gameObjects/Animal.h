#ifndef CROSSING_ROAD_ANIMAL_H
#define CROSSING_ROAD_ANIMAL_H

#include "Obstacle.h"
#include "temp.cpp"
#include "assetsLib/ConfigIO.h"
class Animal : public Obstacle 
{
public:
    Animal(float x, float y, int direction, MainChar *mainChar) : Obstacle(x, y, direction, mainChar) {width=50; height=50;}
    void draw();
    void handleBlockMove() override;
};
#endif 
