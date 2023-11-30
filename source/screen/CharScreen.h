#ifndef CROSSING_ROAD_CHARSCREEN_H
#define CROSSING_ROAD_CHARSCREEN_H

#include "assetsLib/TexturesIO.h"
#include "BaseScreen.h"
#include "gameObjects/Observer.h"
#include <list>
#include "gameObjects/Message.h"
#include <iostream>
#include "gameObjects/MainChar.h"
using namespace std;

class CharScreen : public BaseScreen
{
private:
    //MainChar char;
    //AnimatedTexture *testChar{};
    MainChar mainChar;
    bool hasInit = false;
    

public:
    CharScreen() = default;
    ~CharScreen();
    void init();

    void handleInput() override;
    void update() override;
    void draw() override;

    void load() override;
    void unload() override;
};

#endif //CROSSING_ROAD_CHARSCREEN_H