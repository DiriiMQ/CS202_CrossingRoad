//
// Created by LENOVO on 11/14/2023.
//

#ifndef CROSSING_ROAD_TESTSCREEN_H
#define CROSSING_ROAD_TESTSCREEN_H
#include "BaseScreen.h"
#include "assetsLib/TexturesIO.h"
#include "gameObjects/Road.h"

class TestScreen : public BaseScreen {
private:
    AnimatedTexture *test{};
    vector<Road*> roads;
    bool hasInit = false;

public:
    TestScreen() = default;
    ~TestScreen();
    void init();

    void handleInput() override;
    void update() override;
    void draw() override;

    void load() override;
    void unload() override;
};


#endif //CROSSING_ROAD_TESTSCREEN_H
