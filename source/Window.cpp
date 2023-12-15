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
    int screenWidth = BasicConfigInstance::getData()["SCREEN"]["SIZE"]["WIDTH"];
    int screenHeight = BasicConfigInstance::getData()["SCREEN"]["SIZE"]["HEIGHT"];
    std::string screenTitle = BasicConfigInstance::getData()["SCREEN"]["TITLE"];
    int fps = BasicConfigInstance::getData()["SCREEN"]["FRAMES_PER_SECOND"];
//    std::cerr << "Window::presetWindow " << screenWidth << " " << screenHeight << " " << screenTitle << " " << fps << std::endl;

    InitWindow(
            screenWidth,
            screenHeight,
            screenTitle.c_str());

    SetTargetFPS(fps);
    GuiLoadStyle(BasicConfigInstance::getData()["SCREEN"]["GUI_STYLE"].get<std::string>().c_str());
    GuiSetFont(LoadFont(BasicConfigInstance::getData()["SCREEN"]["GUI_FONT"].get<std::string>().c_str()));
}

void Window::presetScreens() {
    this->menuScreen.setScreenManager(&this->screenManager);
    this->screenManager.setScreen(&this->menuScreen);
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
}
