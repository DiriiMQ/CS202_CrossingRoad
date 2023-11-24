//
// Created by dirii on 30/10/23.
//

#ifndef CROSSING_ROAD_MENUSCREEN_H
#define CROSSING_ROAD_MENUSCREEN_H

#include "BaseScreen.h"
#include "assetsLib/TexturesIO.h"
#include "TestScreen.h"
#include "CharScreen.h"

class MenuScreen : public BaseScreen {
private:
    AnimatedTexture *test{};
    bool hasInit = false;
    TestScreen testScreen;
    CharScreen charScreen;
     
public:
    MenuScreen() = default;
    ~MenuScreen();
    void init();

    void handleInput() override;
    void update() override;
    void draw() override;

    void load() override;
    void unload() override;
};


#endif //CROSSING_ROAD_MENUSCREEN_H
