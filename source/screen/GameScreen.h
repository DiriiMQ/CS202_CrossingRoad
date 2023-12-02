//
// Created by LENOVO on 11/14/2023.
//

#ifndef CROSSING_ROAD_GAMESCREEN_H
#define CROSSING_ROAD_GAMESCREEN_H
#include "BaseScreen.h"
#include "assetsLib/TexturesIO.h"
#include "gameObjects/Road.h"
#include "gameObjects/BaseGameObject.h"
#include "gameObjects/NonRoad.h"
#include "gameObjects/Observer.h"
#include "gameObjects/Message.h"
#include "gameObjects/River.h"
#include "gameObjects/MainChar.h"
#include "Position.h"

class GameScreen : public BaseScreen, public IObserver {
private:
    AnimatedTexture *test{};
    vector<BaseGameObject*> map; // only road and nonroad, maybe river later
    bool hasInit = false;
    MainChar *mainChar;
    MainPos mainPos;
    Rectangle mainPosRec;
    void randomNewBlock();
    int score = 0;
    bool isGamePause=false;

public:
    GameScreen() = default;
    ~GameScreen();
    void init();

    void handleInput() override;
    void update() override;
    void updateMessage(const Message message) override;
    void Observe();


    void draw() override;

    void load() override;
    void unload() override;
    void NotifyMainPos();
    void NotifyPauseGame();

};


#endif //CROSSING_ROAD_GAMESCREEN_H
