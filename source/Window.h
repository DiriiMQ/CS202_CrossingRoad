//
// Created by dirii on 26/10/23.
//

#ifndef CROSSING_ROAD_WINDOW_H
#define CROSSING_ROAD_WINDOW_H

#include <string>

#include "assetsLib/ConfigIO.h"
#include "screen/ImportScreens.h"

class Window {
private:
    bool hasInit = false;
    ScreenManager screenManager;
    MenuScreen menuScreen;

public:
    Window() = default;
    ~Window() = default;

    void init();
    void presetWindow();
    void presetScreens();

    void run();
};


#endif //CROSSING_ROAD_WINDOW_H
