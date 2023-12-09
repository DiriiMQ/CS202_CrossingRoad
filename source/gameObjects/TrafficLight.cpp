#include "TrafficLight.h"

void TrafficLight::init(double x,double y)
{
    this->x=x;
    this->y=y;
}
void TrafficLight::draw()
{
    if (isRed) DrawCircle(float(35),float(y+35),float(5),RED);
    else DrawCircle(float(35),float(y+35),float(5),BLUE);
}
void TrafficLight::setRed()
{
    if (!isRed) isRed=true;
}
void TrafficLight::setGreen()
{
    if (isRed) isRed=false;
}
