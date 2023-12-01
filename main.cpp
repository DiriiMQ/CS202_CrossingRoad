#include <iostream>

// Do not change the order of first two lines below
#define RAYLIB_ASEPRITE_IMPLEMENTATION
#include "raylib-aseprite.h"

#include "Window.h"
#include "assetsLib/ConfigIO.h"
#include "_raygui.h"
#define RAYLIB_ASEPRITE_IMPLEMENTATION

int main() {
    srand(time(0));

    Window window;
    window.run();
//    BasicConfigInstance *config = BasicConfigInstance::getInstance();
//    config->getData()["SCREEN"]["TEST"] = 10;
//    std::cout << config->getData()["SCREEN"]["TEST"] << std::endl;
    BasicConfigInstance::destroyInstance();
    return 0;
}
