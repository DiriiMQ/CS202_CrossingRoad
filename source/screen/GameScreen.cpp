//
// Created by LENOVO on 11/14/2023.
//

#include "GameScreen.h"

void GameScreen::handleInput() {
    for(BaseGameObject *block: map) {
        block->handleInput();
    }
}

void GameScreen::update() {

}

void GameScreen::updateMessage(const Message message) {
    if(message == Message::BLOCK_OUT_OF_SCREEN) {
        cout << "UPDATE CALLED!" << endl;
        int randomNumber = rand();
        BaseGameObject *block;

        if (randomNumber % 2 == 0) {
            block = new Road(-100, 0, 3);
        } else {
            block = new NonRoad(-100, 0);
        }
        block->Attach(this);
        map.push_back(block);

        map.erase(map.begin());
    }
}

void GameScreen::Observe() {
    for (BaseGameObject *subject: map) {
        subject->Attach(this);
    }

}

void GameScreen::draw() {
    Rectangle buttonRect {50, 50, 200, 100};
    if(GuiButton(buttonRect, "Back!")) {
        screenManager->backScreen();
    }
    for(BaseGameObject *block: map) {
        block->draw();
    }
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
    cout << "Test Screen inti Called" << endl;
    for (int i = 0; i < 20; i++) {
        int randnum = rand();
        if (randnum % 2 == 0) {
            Road *roadBlock = new Road(-100, 48 * (19 - i), 1);
            map.push_back(roadBlock);
        } else {
            NonRoad *nonRoadBlock = new NonRoad(-100, 48 * (19 - i));
            map.push_back(nonRoadBlock);

        }
    }
    Observe();

    this->test = new AnimatedTexture("../assets/slime/Jump.png", 13);
}

GameScreen::~GameScreen() {
    for(BaseGameObject *road: map)
        delete road;
};

