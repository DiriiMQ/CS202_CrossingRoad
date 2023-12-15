//
// Created by dirii on 30/10/23.
//

#include "MenuScreen.h"

void MenuScreen::handleInput() {
    //playButton->handleInput();
}

void MenuScreen::update() {
}

void MenuScreen::draw() {

    DrawText("Duong Bao!", 10, 10, 20, RED);

    Rectangle buttonRect {50, 50, 200, 100};
    if(GuiButton(buttonRect, "Click Me!")) {
        screenManager->setScreen(&testScreen);
    }

    Rectangle tempRec{0, 0, (float) this->screenWidth, (float) this->screenHeight};
    DrawTextureRec(bgImage, tempRec, {0,0}, WHITE);
//    drawButtons();
}

void MenuScreen::drawButtons() {
    //playButton->draw();
}

void MenuScreen::load() {
    BaseScreen::load();

    //playButton = new TexturedButton("../assets/welcome_screen/b_play.png");
    Image bgTemp = LoadImage("../assets/welcome_screen/menu_background.png");
    bgImage = LoadTextureFromImage(bgTemp);

    if (!this->hasInit) {
        this->init();
        this->hasInit = true;
    }
}

void MenuScreen::unload() {
    UnloadTexture(bgImage);
    BaseScreen::unload();
}

void MenuScreen::init() {
    this->testScreen.setScreenManager(this->screenManager);

    // set screen variable
    this->screenHeight = BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["HEIGHT"];
    this->screenWidth = BasicConfigInstance::getData(ConfigType::BASIC)["SCREEN"]["SIZE"]["WIDTH"];
}

MenuScreen::~MenuScreen() {
    delete test;

    UnloadAseprite(this->testAseprite); // testing
}