//
// Created by dirii on 30/10/23.
//

#include "MenuScreen.h"

void MenuScreen::handleInput() {

}

void MenuScreen::update() {

}

void MenuScreen::draw() {
    DrawText("Duong Bao!", 10, 10, 20, RED);

    // for testing
    static int cnt = 0, curr = 0;
    if (cnt++ > 5) {
        cnt = 0;
        curr = (curr + 1) % 8;
    }
    this->test->draw({100, 100}, curr);

    Rectangle buttonRect {50, 50, 200, 100};
    if(GuiButton(buttonRect, "Click Me!")) {
        screenManager->setScreen(&testScreen);
    }
}

void MenuScreen::load() {
    BaseScreen::load();

    if (!this->hasInit) {
        this->init();
        this->hasInit = true;
    }
}

void MenuScreen::unload() {
    BaseScreen::unload();
}

void MenuScreen::init() {
    this->test = new AnimatedTexture("../assets/slime/Attack_1.png", 4);
    this->testScreen.setScreenManager(this->screenManager);

    this->testAseprite = new Aseprite("../assets/animal/Cat.aseprite");

}

MenuScreen::~MenuScreen() {
    delete test;
}