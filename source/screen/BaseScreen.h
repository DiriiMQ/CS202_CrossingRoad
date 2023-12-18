//
// Created by dirii on 30/10/23.
//

#ifndef CROSSING_ROAD_BASESCREEN_H
#define CROSSING_ROAD_BASESCREEN_H

#include "ScreenManager.h"
#include "raygui.h"

class ScreenManager;

class BaseScreen {
private:
    bool loaded = false;

protected:
    ScreenManager *screenManager;

public:
    BaseScreen() = default;
    ~BaseScreen() = default;

    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;

    void setScreenManager(ScreenManager *screenManager);

    virtual void unload();
    virtual void load();

    virtual bool isManager();
    [[nodiscard]] bool isLoaded() const;


};


#endif //CROSSING_ROAD_BASESCREEN_H
