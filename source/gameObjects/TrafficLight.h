#ifndef CROSSING_ROAD_TRAFFICLIGHT_H
#define CROSSING_ROAD_TRAFFICLIGHT_H

#include "BaseGameObject.h"
#include <ctime>
#include "raylib-aseprite.h"

class TrafficLight : public BaseGameObject {
private:
    Aseprite sprite;
    AsepriteTag tag;
public:
    void init(double x,double y);
    bool isRed=false;
    void draw() override;

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