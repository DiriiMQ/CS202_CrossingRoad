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
    if (cnt++ > 8) {
        cnt = 0;
        curr = (curr + 1) % 8;
    }
    this->test->draw({100, 100}, curr);
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
    this->test = new AnimatedTexture("../assets/slime/Idle.png", 8);
}
