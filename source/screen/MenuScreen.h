//
// Created by dirii on 30/10/23.
//

#ifndef CROSSING_ROAD_MENUSCREEN_H
#define CROSSING_ROAD_MENUSCREEN_H

#include "BaseScreen.h"
#include "assetsLib/TexturesIO.h"
#include "GameScreen.h"
#include <string>
#include "raylib-aseprite.h"

class MenuScreen : public BaseScreen {
private:
    Texture2D background{};

    AnimatedTexture *test{};
    bool hasInit = false;
    GameScreen gameScreen;

    Vector2 buttonOptionMenuSize {344, 77};

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
