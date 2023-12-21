//
// Created by LENOVO on 11/30/2023.
//

#ifndef CROSSING_ROAD_RIVER_H
#define CROSSING_ROAD_RIVER_H

#include "BaseGameObject.h"
#include "raygui.h"
#include "assetsLib/ConfigIO.h"
#include "Boat.h"
#include <iostream>
#include "MainChar.h"

class River : public BaseGameObject, public IObserver {
private:
    Rectangle mainPosRect;
    vector<Boat*> boats;
    int direction = 1;
    MainChar *mainChar;


public:
    River(float x, float y, int num_boats = 5, MainChar *mainChar = nullptr);
    void draw() override;
    void handleInput() override;
    void updateMainPos(Rectangle mainPosRect) override;
    void updateMessage(const Message message) override;
    void handleBlockOutOfScreen();

    void moveY(double offset) override;
};


#endif //CROSSING_ROAD_RIVER_H
