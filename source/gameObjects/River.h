//
// Created by LENOVO on 11/30/2023.
//

#ifndef CROSSING_ROAD_RIVER_H
#define CROSSING_ROAD_RIVER_H

#include "BaseGameObject.h"
#include "raygui.h"

class River : public BaseGameObject {
private:
    int stepSize = 48;
    Rectangle mainPosRect;
public:
    River(int x, int y) : BaseGameObject(x, y) {};
    void draw() override;
    void handleInput() override;
    void updateMainPos(Rectangle mainPosRect) override {};
};


#endif //CROSSING_ROAD_RIVER_H
