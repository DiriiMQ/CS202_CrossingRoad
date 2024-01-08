#ifndef CROSSING_ROAD_ANIMAL_H
#define CROSSING_ROAD_ANIMAL_H

#include "Obstacle.h"
#include "temp.cpp"
#include "assetsLib/ConfigIO.h"
class Animal : public Obstacle {
private:
    Aseprite sprite;
    AsepriteTag spriteTag;
public:
    Animal(): Obstacle() {}
    Animal(float x, float y, int direction, MainChar *mainChar) : Obstacle(x, y, direction, mainChar) {
        int randIndex = -1;
        sprite = AsepriteInstance::getAseprite(AsepriteType::ANIMAL, randIndex);
        vector<string> tagList = BasicConfigInstance::getData(ConfigType::BASIC)["TEXTURES"]["ANIMAL_TAG"];

        string tag = direction == 1 ? "l2r" : tagList[randIndex];

        spriteTag = LoadAsepriteTag(sprite, tag.c_str());

        width = GetAsepriteWidth(sprite) * 1.5;
        height = GetAsepriteHeight(sprite) * 1.5;
        objectIndex = randIndex;

    }
    void draw();
    void handleBlockMove() override;
    void handleInput() override;
};
#endif 
