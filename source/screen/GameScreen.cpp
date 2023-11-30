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
    if(message == Message::BLOCK_OUT_OF_SCREEN) {
        cout << "UPDATE CALLED!" << endl;
        randomNewBlock();
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
};

