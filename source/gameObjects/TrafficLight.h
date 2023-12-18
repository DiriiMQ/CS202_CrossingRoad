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
    TrafficLight(double x, double y) : BaseGameObject(x, y) {
        sprite = LoadAseprite("../assets/trafficLights/TrafficLights.aseprite");
    };

    bool isRed = false;
    void draw() override;

    void handleInput();
    void updateMainPos(Rectangle mainPosRect) override {}

};
#endif //CROSSING_ROAD_TRAFFICLIGHT_H