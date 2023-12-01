//
// Created by dirii on 30/10/23.
//

#include "MenuScreen.h"

void MenuScreen::handleInput() {

}

void MenuScreen::update() {
    UpdateAsepriteTag(&this->testWalkdown);
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
    Rectangle buttonRect2 {500, 50, 200, 100};
    if(GuiButton(buttonRect2, "Test Me!")) {
        screenManager->setScreen(&charScreen);
    }

    // Draw the first frame from the George sprite.
    DrawAseprite(this->testAseprite, 0, 100, 400, WHITE);
    // Draw the Walk Down animation.
    DrawAsepriteTag(this->testWalkdown, 200, 400, WHITE);
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
    this->charScreen.setScreenManager(this->screenManager);

    this->testAseprite = LoadAseprite("../assets/george.aseprite");
    this->testWalkdown = LoadAsepriteTag(this->testAseprite, "Walk-Down");
    this->testWalkdown.speed = 2;
}

MenuScreen::~MenuScreen() {
    delete test;

    UnloadAseprite(this->testAseprite);
}