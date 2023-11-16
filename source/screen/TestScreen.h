//
// Created by LENOVO on 11/14/2023.
//

#ifndef CROSSING_ROAD_TESTSCREEN_H
#define CROSSING_ROAD_TESTSCREEN_H
#include "BaseScreen.h"
#include "assetsLib/TexturesIO.h"
#include "gameObjects/Road.h"
#include "gameObjects/BaseGameObject.h"
#include "gameObjects/NonRoad.h"
#include "gameObjects/Observer.h"
#include "gameObjects/Message.h"

class TestScreen : public BaseScreen, public IObserver {
private:
    AnimatedTexture *test{};
    vector<BaseGameObject*> map;
    bool hasInit = false;

public:
    TestScreen() = default;
    ~TestScreen();
    void init();

    void handleInput() override;
    void update() override;
    void Update(const Message message) override;
    void Observe();


    void draw() override;

    void load() override;
    void unload() override;
};


#endif //CROSSING_ROAD_TESTSCREEN_H
