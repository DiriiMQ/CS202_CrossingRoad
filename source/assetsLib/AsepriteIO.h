//
// Created by LENOVO on 12/15/2023.
//

#ifndef CROSSING_ROAD_ASEPRITEIO_H
#define CROSSING_ROAD_ASEPRITEIO_H

#include "raylib.h"
#include "raylib-aseprite.h"
#include <mutex>
#include <utility>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include "assetsLib/ConfigIO.h"
#include "utils/RandomNumber.h"
class AsepriteIO {

private:
    Aseprite aseprite;

public:
    AsepriteIO() = default;
    ~AsepriteIO() = default;

    void loadAseprite(std::string path);

    Aseprite& getAseprite();
};

class AnimatedAsepriteConfig : public AsepriteIO {
private:
    std::string ANIMATED_ASEPRITE_PATH = "../assets/configs/animatedAseprite.json";
public:

    AnimatedAsepriteConfig() = default;
    explicit  AnimatedAsepriteConfig(std::string path);
    ~AnimatedAsepriteConfig();

    void loadAseprite();
};

namespace AsepriteType {
    enum AsepriteType {
        ANIMATED,
        STATIC,
        BOAT
    };
}

class AsepriteInstance {
private:
    static AsepriteInstance* instance[3];
    static std::mutex _mutex;
    std::vector<AnimatedAsepriteConfig> aseprite;
protected:
    AsepriteInstance() = default;
    ~AsepriteInstance() = default;

public:
    AsepriteInstance(const AsepriteInstance&) = delete;
    AsepriteInstance& operator=(const AsepriteInstance&) = delete;

    static void initInstance();

    static AsepriteInstance *getInstance(int id = 0);

    static Aseprite &getAseprite(int id, int &randIndex);

};


#endif //CROSSING_ROAD_ASEPRITEIO_H
