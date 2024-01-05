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
//    DrawText("Duong Bao!", 10, 10, 20, RED); // Sorry bro, have to delete this :(

    this->buttonsProcess();
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

    // set screen variable
    this->screenHeight = BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["HEIGHT"];
    this->screenWidth = BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"];
    this->gameScreen.setScreenManager(this->screenManager);
}

MenuScreen::~MenuScreen() {
    UnloadTexture(this->background);
}

void MenuScreen::buttonsProcess() {
    Rectangle buttonRect = {
            (float) (GetScreenWidth() - this->buttonOptionMenuSize.x) / 2,
            (float) (GetScreenHeight() - this->buttonOptionMenuSize.y) / 2,
            this->buttonOptionMenuSize.x,
            this->buttonOptionMenuSize.y
    };
    if(GuiButtonRounded(buttonRect, "New Game")) {
        gameScreen.init();
        screenManager->setScreen(&gameScreen);
    }

    buttonRect.y += this->buttonOptionMenuSize.y + 28;
    if(GuiButtonRounded(buttonRect, "Load Game")) {
        std::ifstream file("../data/save_game.json");
        if(file.good()) {
            gameScreen.loadScreen();
            screenManager->setScreen(&gameScreen);
        }
    }

    buttonRect.y += this->buttonOptionMenuSize.y + 28;
    if(GuiButtonRounded(buttonRect, "Leaderboard")) {

    }
}
