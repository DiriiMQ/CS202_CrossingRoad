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
#include "../UI/TexturedButton.h"

class MenuScreen : public BaseScreen {
private:
    AnimatedTexture *test{};
    bool hasInit = false;
    GameScreen testScreen;

    // for testing
    Aseprite testAseprite;
    AsepriteTag testWalkdown;
    Texture bgImage;

    // screen var
    int screenWidth;
    int screenHeight;

public:
    MenuScreen() = default;
    ~MenuScreen();
    void init();

    void handleInput() override;
    void update() override;
    void draw() override;

    // draw functions
    void drawButtons();

    void load() override;
    void unload() override;

};


#endif //CROSSING_ROAD_MENUSCREEN_H
