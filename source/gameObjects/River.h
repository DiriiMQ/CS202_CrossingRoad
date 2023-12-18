//
// Created by LENOVO on 11/30/2023.
//

#ifndef CROSSING_ROAD_RIVER_H
#define CROSSING_ROAD_RIVER_H

#include "BaseGameObject.h"
#include "raygui.h"
#include "assetsLib/ConfigIO.h"

class River : public BaseGameObject {
private:
    Rectangle mainPosRect;
public:
    River(double x, double y) : BaseGameObject(x, y) {};
    void draw() override;
    void handleInput() override;
    void updateMainPos(Rectangle mainPosRect) override {};
};


#endif //CROSSING_ROAD_RIVER_H
