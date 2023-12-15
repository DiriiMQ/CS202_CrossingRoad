//
// Created by dirii on 30/10/23.
//

#include "MenuScreen.h"

void MenuScreen::handleInput() {

}

void MenuScreen::update() {

}

void MenuScreen::draw() {
    DrawTexture(this->background, 0, 0, WHITE);
    DrawText("Duong Bao!", 10, 10, 20, RED);

    Rectangle buttonRect = {
            (float) (GetScreenWidth() - this->buttonOptionMenuSize.x) / 2,
            (float) (GetScreenHeight() - this->buttonOptionMenuSize.y) / 2,
            this->buttonOptionMenuSize.x,
            this->buttonOptionMenuSize.y
    };
    if(GuiButtonRounded(buttonRect, "New Game")) {
        screenManager->setScreen(&gameScreen);
    }

    buttonRect.y += this->buttonOptionMenuSize.y + 28;
    if(GuiButtonRounded(buttonRect, "Load Game")) {

    }

    buttonRect.y += this->buttonOptionMenuSize.y + 28;
    if(GuiButtonRounded(buttonRect, "Leaderboard")) {

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
    this->background = LoadTexture(
            BasicConfigInstance::getData()["BACKGROUND"]["MENU"].get<std::string>().c_str()
            );

    this->test = new AnimatedTexture("../assets/slime/Attack_1.png", 4);
    this->gameScreen.setScreenManager(this->screenManager);
}

MenuScreen::~MenuScreen() {
    delete test;

    UnloadTexture(this->background);
}