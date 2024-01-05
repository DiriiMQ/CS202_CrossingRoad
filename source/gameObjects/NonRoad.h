//
// Created by LENOVO on 11/17/2023.
//

#ifndef CROSSING_ROAD_NONROAD_H
#define CROSSING_ROAD_NONROAD_H
#include "BaseGameObject.h"
#include "raylib.h"
#include "raylib-aseprite.h"
#include "Obstacle.h"
#include <vector>
#include "assetsLib/ConfigIO.h"
#include "MainChar.h"
#include "Animal.h"

class NonRoad : public BaseGameObject {
private:
    std::vector<Obstacle*> staticObs;
    Obstacle* nonStaticObs;
    MainChar *mainChar;
    bool hasAnimal;
public:
    NonRoad() : BaseGameObject(0.0, 0.0), mainChar(nullptr) {};
    NonRoad(float x, float y, int numStatic = 5, MainChar *mainChar = nullptr);
    void draw() override;
    void handleInput() override;
    void updateMainPos(Rectangle mainPosRect) override {};
//    void setScreenSpeed(double speed) override;
    void moveY(double offset) override;

    json toJson() override;
    void fromJson(json saveData) override;
    void setMainChar(MainChar *mainChar);

    string getClassName() override {
        return "NonRoad";
    }

    ~NonRoad();
   
};


#endif //CROSSING_ROAD_NONROAD_H
