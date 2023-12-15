//
// Created by LENOVO on 12/13/2023.
//

#ifndef CROSSING_ROAD_TEXTUREDBUTTON_H
#define CROSSING_ROAD_TEXTUREDBUTTON_H

#include "raylib-aseprite.h"
#include "raygui.h"
#include <string>
#include <iostream>

class TexturedButton {
    Rectangle bounds;
    Texture2D texture;
    bool isHovered;

public:
    bool isPressed;

    TexturedButton(std::string textureFile);

    bool isMouseOver();
    bool isButtonPressed();

    void handleInput();
    void draw();

    ~TexturedButton();
};


#endif //CROSSING_ROAD_TEXTUREDBUTTON_H
