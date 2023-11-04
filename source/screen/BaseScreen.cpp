//
// Created by dirii on 30/10/23.
//

#include "BaseScreen.h"

bool BaseScreen::isManager() {
    return false;
}

bool BaseScreen::isLoaded() const {
    return this->loaded;
}

void BaseScreen::unload() {
    this->loaded = false;
}

void BaseScreen::load() {
    this->loaded = true;
}

void BaseScreen::setScreenManager(ScreenManager *_screenManager) {
    this->screenManager = _screenManager;
}
