//
// Created by LENOVO on 12/13/2023.
//

#include "TexturedButton.h"

TexturedButton::TexturedButton(std::string textureFile) {
    Image tempImage = LoadImage(textureFile.c_str());
    texture = LoadTextureFromImage(tempImage);
    bounds.width = texture.width;
    bounds.height = texture.height;
    bounds.x = 0;
    bounds.y = 0;
    UnloadImage(tempImage);

}

bool TexturedButton::isMouseOver() {
    Vector2 mousePosition = GetMousePosition();
    return CheckCollisionPointRec(mousePosition, bounds);
}

bool TexturedButton::isButtonPressed() {
    return isMouseOver() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void TexturedButton::handleInput() {
    isPressed = isButtonPressed();
    isHovered = isMouseOver();
}

void TexturedButton::draw() {
    Color color = isHovered ? YELLOW : WHITE;
    DrawTexture(this->texture, 0, 0, color);
}

TexturedButton::~TexturedButton() {
    UnloadTexture(texture);
}