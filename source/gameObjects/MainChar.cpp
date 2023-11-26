#include "MainChar.h"
double lastUpdate=0;

bool eventTriggered(double interval)
{
    double currentTime=GetTime();
    if (currentTime-lastUpdate >=interval)
    {
        lastUpdate=currentTime;
        return true;
    }
    return false;
}
void MainChar::draw()
{
    DrawRectangle(x, y, 50, 50, BLUE);
}
void MainChar::handleInput()
{
    
    
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        if (eventTriggered(0.15))
        x -= stepSize;
        cout<<getPos().x<<" "<<getPos().y<<endl;
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        if (eventTriggered(0.15))
        x += stepSize;
        cout<<getPos().x<<" "<<getPos().y<<endl;
    }
}
Vector2 MainChar::getPos()
{
    Vector2 position = (Vector2){float (x),float (y)};
    return position;
    
}
Rectangle MainChar::returnMainPos()
{
    Rectangle rect1 = { float (x),float (y), 50, 50 };
    return rect1;
}

