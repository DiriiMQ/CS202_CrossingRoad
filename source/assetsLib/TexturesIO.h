//
// Created by dirii on 2/11/23.
//

#ifndef CROSSING_ROAD_TEXTURESIO_H
#define CROSSING_ROAD_TEXTURESIO_H

#include <string>

#include "raygui.h"
#include "ConfigIO.h"

class TextureIO {
protected:
    std::string path;
    Texture2D texture{};

public:
    TextureIO() = default;
//    TextureIO(const TextureIO&) = delete;
    ~TextureIO() = default;

    void loadTexture(std::string _path);
    Texture2D& getTexture();

    void draw(Vector2 position, Color tint = WHITE);
    void draw(Vector2 position, Rectangle source, Color tint = WHITE);
};

class AnimatedTexture: public TextureIO {
private:
    int frames;

public:
    AnimatedTexture() = default;
//    AnimatedTexture(const AnimatedTexture&) = delete;
    AnimatedTexture(std::string _path, int _frames);
    ~AnimatedTexture() = default;

    void draw(Vector2 position, int currentFrame, Color tint = WHITE);
};

#endif //CROSSING_ROAD_TEXTURESIO_H
