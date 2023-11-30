#include <iostream>

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
