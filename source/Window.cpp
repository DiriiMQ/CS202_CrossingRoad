//
// Created by dirii on 26/10/23.
//

#include "Window.h"

#include <iostream>

void Window::init() {
    this->presetWindow();
    this->presetScreens();
}

void Window::presetWindow() {
    BasicConfigInstance *config = BasicConfigInstance::getInstance();
    int screenWidth = config->getData()["SCREEN"]["SIZE"]["WIDTH"];
    int screenHeight = config->getData()["SCREEN"]["SIZE"]["HEIGHT"];
    std::string screenTitle = config->getData()["SCREEN"]["TITLE"];
    int fps = config->getData()["SCREEN"]["FRAMES_PER_SECOND"];
//    std::cerr << "Window::presetWindow " << screenWidth << " " << screenHeight << " " << screenTitle << " " << fps << std::endl;

    InitWindow(
            screenWidth,
            screenHeight,
            screenTitle.c_str());

    SetTargetFPS(fps);
}

void Window::presetScreens() {
    this->screenManager.setScreen(&this->menuScreen);

    this->menuScreen.setScreenManager(&this->screenManager);
}

void Window::run() {
    if (!this->hasInit) {
        this->init();
        this->hasInit = true;
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
        this->screenManager.handleInput();
        this->screenManager.update();
        this->screenManager.draw();
        EndDrawing();
    }

    CloseWindow();
}
