#ifndef CROSSING_ROAD_TRAFFICLIGHT_H
#define CROSSING_ROAD_TRAFFICLIGHT_H

#include "BaseGameObject.h"
#include <ctime>
#include "raylib-aseprite.h"
#include "MainChar.h"

class TrafficLight : public BaseGameObject {
private:
    Aseprite sprite;
    AsepriteTag tag;
    MainChar *mainChar;

public:
    TrafficLight(float x, float y, MainChar *mainChar) : BaseGameObject(x, y), mainChar(mainChar) {
        sprite = LoadAseprite("../assets/trafficLights/TrafficLights.aseprite");
    };

    bool isRed = false;
    void draw() override;

    void handleInput();
    void updateMainPos(Rectangle mainPosRect) override {}

};
#endif //CROSSING_ROAD_TRAFFICLIGHT_H