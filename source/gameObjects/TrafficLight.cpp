#include "TrafficLight.h"

void TrafficLight::draw() {
//    y += screenSpeed;
    tag = LoadAsepriteTag(sprite, isRed ? "red" : "green");
    DrawAsepriteTag(tag, 50, y + 20, WHITE);
}

json TrafficLight::toJson() {
    json saveData = BaseGameObject::toJson();
    saveData["isRed"] = isRed;
    return saveData;
}

void TrafficLight::fromJson(json saveData) {
    BaseGameObject::fromJson(saveData);
    isRed = saveData["isRed"];
}

void TrafficLight::handleInput() {
    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && mainChar->canMoveUp) {
        y += stepSize;
    }
}