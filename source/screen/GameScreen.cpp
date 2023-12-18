//
// Created by LENOVO on 11/14/2023.
//

#include "GameScreen.h"

void GameScreen::NotifyMainPos()
{
    for (BaseGameObject *subject: map) {
        subject->updateMainPos(mainChar->returnMainPos());
        subject->setMainCharacterDead(mainChar->getDead());
    }
}

void GameScreen::handleInput() {

    if (isGamePause) return;

    if (!mainChar->getDead()) {
        for (BaseGameObject *block: map) {
            block->handleInput();
        }
        if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && !mainChar->getDead()) {
            score += 1;
        }
        mainChar->handleInput();
    }
    handleScreenSpeed();

}

void GameScreen::update() {
    NotifyMainPos();
}

void GameScreen::randomNewBlock() {
    int randomNumber = rand();

    BaseGameObject *block;

    if (randomNumber % 100 > 60) {
        block = new Road(-100.0, map[map.size() - 1]->getY()-48, 5);
    }
    else if(randomNumber % 100 > 40) {
        block = new River(-100.0, map[map.size() - 1]->getY()-48);
    }
    else {
        block = new NonRoad(-100.0, map[map.size() - 1]->getY()-48, 3);
    }
    block->Attach(this);
    //block->setScreenSpeed(screenSpeed);
    map.push_back(block);

}

void GameScreen::updateMessage(const Message message) {

    if (message == Message::BLOCK_OUT_OF_SCREEN){
        randomNewBlock();
        map.erase(map.begin());
    }
    else if (message == Message::COLLISION) {
        mainChar->setDead();
    }

}

void GameScreen::Observe() {
    for (BaseGameObject *subject: map) {
        subject->Attach(this);
    }
    mainChar->Attach(this);
}

void GameScreen::draw() {

    for(BaseGameObject *block: map) {
//        block->setScreenSpeed(screenSpeed);
        block->draw();
//        block->moveY(0.1);
    }
//    mainChar->setScreenSpeed(screenSpeed);
    mainChar->draw();
    if (!this->isGamePause) {
        Rectangle buttonRectPause {900, 50, 100, 100};
        if (GuiButton(buttonRectPause, "Pause!")) {
            NotifyPauseGame();
            this->isGamePause=!(this->isGamePause);
         }
    }
    else {
        DrawRectangle  (400, 100, 600, 600, GRAY);
        Rectangle continueButton {450, 300, 500, 100};
        if (GuiButton(continueButton, "Continue")) {
            this->isGamePause=!(this->isGamePause);
            NotifyPauseGame();
        }
        Rectangle backButton {450, 450, 500, 100};
        if (GuiButton(backButton, "Back"))
        {
            screenManager->backScreen();
        }
        DrawText("Game Pause!", 580, 200, 40, RED);
    }
    if (mainChar->getDead()) 
    {
        DrawRectangle  (400, 100, 600, 600, GRAY);
        Rectangle continueButton {450, 300, 500, 100};
        DrawText("YOU DEAD!", 580, 200, 40, RED);
        Rectangle backButton {450, 450, 500, 100};
        if (GuiButton(backButton, "Back"))
        {
            screenManager->backScreen();
        }
        Rectangle newgameButton {450, 300, 500, 100};
        if (GuiButton(newgameButton, "New game")) {
           /*GameScreen* A = new GameScreen;
           A->init();*/
           //loadScreen(A);
           //A->deleteScreen();
           //delete A;
           this->newGameScreen();

        }
    }
    DrawText(to_string(score).c_str(), 722, 50, 36, GRAY);
//    mainChar->moveY(0.1);

}

void GameScreen::handleScreenSpeed() {
    double charY = mainChar->getY();
    int screenHeight = BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["HEIGHT"];
    if (mainChar->getDead()) {
        screenSpeed = 0.0;
    }
    else if (charY <  screenHeight / 2) {
        screenSpeed = 0.75;
    }
    else if (charY > 626 - 50){
        screenSpeed = 0.25;
    }


    for(BaseGameObject *block: map) {
        block->moveY(screenSpeed);
    }
    mainChar->moveY(screenSpeed);
}

void GameScreen::load() {
    BaseScreen::load();

    if (!this->hasInit) {
        this->init();
        this->hasInit = true;
    }
}

void GameScreen::unload() {
    BaseScreen::unload();
}

void GameScreen::init() {
    cout << "Test Screen init Called" << endl;

    mainChar = new MainChar();
    for (int i = 0; i < 20; i++) {
        int randnum = rand();
        double x_direction = -100;
        double y_direction = 48 * (19 - i);
        if ((randnum % 100 > 60 && i > 10) || i == 10) {
            Road *roadBlock = new Road(x_direction, y_direction, 5);
            map.push_back(roadBlock);
        }
        else if (randnum % 100 > 40 && i > 10) {
            River *riverBlock = new River(x_direction, y_direction);
            map.push_back(riverBlock);
        }
        else {
            NonRoad *nonRoadBlock = new NonRoad(x_direction, y_direction, 15);
            map.push_back(nonRoadBlock);
        }
    }
    Observe();

    this->test = new AnimatedTexture("../assets/slime/Jump.png", 13);
}

void GameScreen::loadScreen(GameScreen* A)
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

void GameScreen::newGameScreen() {
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

void GameScreen::NotifyPauseGame()
{
    for (BaseGameObject *subject: map) {
        subject->pauseGame();
    }
}

GameScreen::~GameScreen() {
    for(BaseGameObject *road: map)
        delete road;

    delete mainChar;
    delete test;
}