//
// Created by dirii on 2/11/23.
//

#include "TexturesIO.h"

#include <utility>

void TextureIO::loadTexture(std::string _path) {
    this->path = std::move(_path);

    this->texture = LoadTexture(this->path.c_str());
}

Texture2D &TextureIO::getTexture() {
    return this->texture;
}

void TextureIO::draw(Vector2 position, Color tint) {
    DrawTexture(this->texture, (int)position.x, (int)position.y, tint);
}

void TextureIO::draw(Vector2 position, Rectangle source, Color tint) {
    DrawTextureRec(this->texture, source, position, tint);
}

AnimatedTexture::AnimatedTexture(std::string _path, int _frames) {
    this->frames = _frames;
    this->loadTexture(std::move(_path));
}

void AnimatedTexture::draw(Vector2 position, int currentFrame, Color tint) {
    int frameWidth = this->texture.width / this->frames;
    int frameHeight = this->texture.height;

    Rectangle source = {
            (float)(currentFrame * frameWidth),
            0,
            (float)frameWidth,
            (float)frameHeight
    };

    TextureIO::draw(position, source, tint);
}
