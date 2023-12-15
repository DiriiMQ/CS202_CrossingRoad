#include <iostream>

// Do not change the order of first two lines below
#define RAYLIB_ASEPRITE_IMPLEMENTATION
#include "raylib-aseprite.h"

#include "Window.h"
#include "assetsLib/ConfigIO.h"
#include "utils/RandomNumber.h"
#include "assetsLib/AsepriteIO.h"
#include "_raygui.h"

int main() {
    srand(time(0));

    auto* window = new Window();
    window->run();

//    BasicConfigInstance::getData(ConfigType::LEADERBOARD)["Quang"] = 100;

    delete window;
    CloseWindow();

//    std::cerr << RandomNumber::getInstance().getRandomNumber(0, 100) << std::endl;
    return 0;
}
