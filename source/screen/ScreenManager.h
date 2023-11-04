//
// Created by dirii on 30/10/23.
//

#ifndef CROSSING_ROAD_SCREENMANAGER_H
#define CROSSING_ROAD_SCREENMANAGER_H

#include <vector>

#include "BaseScreen.h"

class BaseScreen;

class ScreenManager {
private:
    BaseScreen *currentScreen{};
    std::vector<BaseScreen*> stackScreen;

public:
    ScreenManager() = default;
    ~ScreenManager() = default;

    void setScreen(BaseScreen *screen);
    BaseScreen *backScreen();
    BaseScreen *getScreen();
    static bool isManager();

    void handleInput();
    void update();
    void draw();
};


#endif //CROSSING_ROAD_SCREENMANAGER_H
