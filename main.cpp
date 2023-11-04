#include <iostream>

#include "Window.h"
#include "assetsLib/ConfigIO.h"
#include "_raygui.h"

int main() {
    Window window;
    window.run();
//    BasicConfigInstance *config = BasicConfigInstance::getInstance();
//    config->getData()["SCREEN"]["TEST"] = 10;
//    std::cout << config->getData()["SCREEN"]["TEST"] << std::endl;
    BasicConfigInstance::destroyInstance();
    return 0;
}
