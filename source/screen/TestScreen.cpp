//
// Created by LENOVO on 11/14/2023.
//

#include "TestScreen.h"

void TestScreen::handleInput() {
    for(Road *road: roads) {
        road->handleInput();
    }
}

void TestScreen::update() {

}

void TestScreen::draw() {
    Rectangle buttonRect {50, 50, 200, 100};
    if(GuiButton(buttonRect, "Back!")) {
        screenManager->backScreen();
    }
    for(Road *road: roads) {
        road->draw();
    }
}

void TestScreen::load() {
    BaseScreen::load();

    if (!this->hasInit) {
        this->init();
        this->hasInit = true;
    }
}

void TestScreen::unload() {
    BaseScreen::unload();
}

void TestScreen::init() {
    cout << "Test Screen inti Called" << endl;
    Road *testRoad = new Road(-100, 500, 1);
    roads.push_back(testRoad);

    this->test = new AnimatedTexture("../assets/slime/Jump.png", 13);
}

TestScreen::~TestScreen() {
    for(Road *road: roads)
        delete road;
};

