#ifndef CROSSING_ROAD_TRAFFICLIGHT_H
#define CROSSING_ROAD_TRAFFICLIGHT_H

#include "BaseGameObject.h"
#include <ctime>

class TrafficLight : public BaseGameObject {
public:
    void init(double x,double y);
    bool isRed=false;
    void draw() override;
    void setRed();
    void setGreen();
    void handleInput() override {
        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
        {
            y+=48;
        }
    }
    void updateMainPos(Rectangle mainPosRect) override {}
   // void Attach(IObserver *observer) override;
};
#endif //CROSSING_ROAD_TRAFFICLIGHT_H