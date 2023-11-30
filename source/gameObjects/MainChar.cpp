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
//    y += screenSpeed;
    DrawRectangle(x, y, width, height, YELLOW);
}
void MainChar::handleInput()
{

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        if (eventTriggered(0.15))
            x -= stepSizeX;
//        cout<<getPos().x<<" "<<getPos().y<<endl;
    }
    else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        if (eventTriggered(0.15))
            x += stepSizeX;
//        cout<<getPos().x<<" "<<getPos().y<<endl;
    }
    else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        if (eventTriggered(0.15))
            y = 626;
//        cout<<getPos().x<<" "<<getPos().y<<endl;
    }
}
Vector2 MainChar::getPos()
{
    Vector2 position = (Vector2){float (x),float (y)};
    return position;
    
}
Rectangle MainChar::returnMainPos()
{
    Rectangle rect1 = { float (x),float (y), width, height};
    return rect1;
}

