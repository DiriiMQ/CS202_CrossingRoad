#include "TrafficLight.h"

void TrafficLight::init(double x,double y)
{
    this->x=x;
    this->y=y;
    sprite = LoadAseprite("../assets/trafficLights/TrafficLights.aseprite");
}


void TrafficLight::draw()
{
    tag = LoadAsepriteTag(sprite, isRed ? "red" : "green");
    DrawAsepriteTag(tag, 50, y + 20, WHITE);
}