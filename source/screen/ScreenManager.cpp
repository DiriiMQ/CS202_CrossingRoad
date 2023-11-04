//
// Created by dirii on 30/10/23.
//

#include "ScreenManager.h"

void ScreenManager::setScreen(BaseScreen *screen) {
    if (this->currentScreen != nullptr) {
        this->currentScreen->unload();
    }

    this->currentScreen = screen;
    this->currentScreen->load();
    this->stackScreen.push_back(screen);
}

BaseScreen *ScreenManager::getScreen() {
    return this->currentScreen;
}

void ScreenManager::handleInput() {
    this->currentScreen->handleInput();
}

void ScreenManager::update() {
    this->currentScreen->update();
}

void ScreenManager::draw() {
    ClearBackground(WHITE);
    this->currentScreen->draw();
}

bool ScreenManager::isManager() {
    return true;
}

BaseScreen *ScreenManager::backScreen() {
    if (this->currentScreen != nullptr) {
        this->currentScreen->unload();
        this->currentScreen = nullptr;
        this->stackScreen.pop_back();
    }

    if (!this->stackScreen.empty()) {
        this->currentScreen = this->stackScreen.back();
        this->currentScreen->load();
    }

    return this->currentScreen;
}
