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
//    MainPos mainPos;
//    Rectangle mainPosRec;
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
    void loadScreen(GameScreen* A)
    {
        this->test=A->test;
        int sizemap=map.size();
        for (int i=0;i<sizemap;i++) {
            this->map[i]=A->map[i];
        }
        this->mainChar=A->mainChar;
        this->score=0;
        this->isGamePause=false;
    }
    void newGameScreen()
    {
        this->score=0;
        this->isGamePause=false;
        mainChar->resetMainChar();
        mainChar->mainCharRevive();
        int mapsize=map.size();
        for (int i = 0; i < 20; i++) 
        {
        int randnum = rand();
        double x_direction = -100;
        double y_direction = 48 * (19 - i);
        if ((randnum % 100 > 60 && i > 10) || i == 10) {
            Road *roadBlock = new Road(x_direction, y_direction, 5);
            map.push_back(roadBlock);
            //map.erase(map.begin());
        }
        else if (randnum % 100 > 40 && i > 10) {
            River *riverBlock = new River(x_direction, y_direction);
            map.push_back(riverBlock);
            //map.erase(map.begin());
        }
        else {
            NonRoad *nonRoadBlock = new NonRoad(x_direction, y_direction);
            map.push_back(nonRoadBlock);
            //map.erase(map.begin());
        }
        map.erase(map.begin());
        mainChar->mainCharRevive();
        //delete test;
        //map[i]->Notify(Message::NEW_GAME);
        }
        this->test = new AnimatedTexture("../assets/slime/Jump.png", 13);
        
        Observe();
        
        
        
        


    }
};


#endif //CROSSING_ROAD_GAMESCREEN_H
