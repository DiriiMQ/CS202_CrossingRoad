//
// Created by LENOVO on 11/17/2023.
//

#ifndef CROSSING_ROAD_NONROAD_H
#define CROSSING_ROAD_NONROAD_H
#include "BaseGameObject.h"
#include "raylib.h"
#include "raylib-aseprite.h"
#include "Obstacle.h"
#include <vector>
#include "assetsLib/ConfigIO.h"

class NonRoad : public BaseGameObject {
private:
    std::vector<Obstacle*> staticObs;

public:
    NonRoad(float x, float y, int numStatic = 5);
    void draw() override;
    void handleInput() override;
    void updateMainPos(Rectangle mainPosRect) override {};
//    void setScreenSpeed(double speed) override;
    void moveY(double offset) override;
};


#endif //CROSSING_ROAD_NONROAD_H
