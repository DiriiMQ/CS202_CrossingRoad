//
// Created by LENOVO on 11/30/2023.
//

#include "River.h"

void River::handleInput() {

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        y += stepSize;
    }
}

void River::draw() {
//    y += screenSpeed;

    DrawRectangle(x, y, 1500, 50, Color{134, 180, 188, 255});
    json cfg = BasicConfigInstance::getData(ConfigType::BASIC);

    if(y > (int) cfg["SCREEN"]["SIZE"]["HEIGHT"] + (int) cfg["TEXTURES"]["OUT_SCREEN_OFFSET"]) {
        BaseGameObject::Notify();
    }
}