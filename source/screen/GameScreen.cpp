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
}

void GameScreen::update() {
    NotifyMainPos();
}

void GameScreen::randomNewBlock() {
    int randomNumber = rand();

    BaseGameObject *block;

    if (randomNumber % 100 > 60) {
        block = new Road(-100.0, map[map.size() - 1]->getY()-48, 3);
    }
    else if(randomNumber % 100 > 40) {
        block = new River(-100.0, map[map.size() - 1]->getY()-48);
    }
    else {
        block = new NonRoad(-100.0, map[map.size() - 1]->getY()-48);
    }
    block->Attach(this);
    map.push_back(block);

}

void GameScreen::updateMessage(const Message message) {

    if (message == Message::BLOCK_OUT_OF_SCREEN){
        cout << "UPDATE CALLED!" << endl;
        randomNewBlock();
        map.erase(map.begin());
    }
    else if (message == Message::COLLISION) {
        mainChar->setDead();
//        for(BaseGameObject *obj : map) {
//            if (obj) obj->setMove(false);
//        }
    }

}

void GameScreen::Observe() {
    for (BaseGameObject *subject: map) {
        subject->Attach(this);
    }
    mainChar->Attach(this);
}

void GameScreen::draw() {
    //Rectangle buttonRect {50, 50, 200, 100};
   // if(GuiButton(buttonRect, "Back!")) {
   //     screenManager->backScreen();
   // }
    for(BaseGameObject *block: map) {
        block->draw();
//        block->moveY(0.1);
    }
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
            NonRoad *nonRoadBlock = new NonRoad(x_direction, y_direction);
            map.push_back(nonRoadBlock);
        }
    }
    Observe();

    this->test = new AnimatedTexture("../assets/slime/Jump.png", 13);
}

GameScreen::~GameScreen() {
    for(BaseGameObject *road: map)
        delete road;

    delete mainChar;
    delete test;
}
void GameScreen::NotifyPauseGame()
{
    for (BaseGameObject *subject: map) {
        subject->pauseGame();
    }
}
