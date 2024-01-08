//
// Created by LENOVO on 12/15/2023.
//

#include "AsepriteIO.h"

void AsepriteIO::loadAseprite(std::string path) {
    this->aseprite = LoadAseprite(path.c_str());

}

Aseprite &AsepriteIO::getAseprite() {
    return this->aseprite;
}

void AnimatedAsepriteConfig::loadAseprite() {
    AsepriteIO::loadAseprite(this->ANIMATED_ASEPRITE_PATH.c_str());
}

AnimatedAsepriteConfig::AnimatedAsepriteConfig(std::string path) {
    this->ANIMATED_ASEPRITE_PATH = std::move(path);
    this->loadAseprite();
}

AnimatedAsepriteConfig::~AnimatedAsepriteConfig() {
    std::cout << "AnimatedAsepriteConfig::~AnimatedAsepriteConfig() called!" << std::endl;
}

AsepriteInstance* AsepriteInstance::instance[4] = {nullptr, nullptr, nullptr, nullptr};
std::mutex AsepriteInstance::_mutex;

void AsepriteInstance::initInstance() {
        std::lock_guard<std::mutex> lock(_mutex);
        if (AsepriteInstance::instance[0] == nullptr) {
            AsepriteInstance::instance[0] = new AsepriteInstance();
            std::vector<std::string> textureList = BasicConfigInstance::getData(ConfigType::BASIC)["TEXTURES"]["OBSTACLES"];
            for (const auto &texture_path : textureList) {
                instance[0]->aseprite.emplace_back(AnimatedAsepriteConfig(texture_path));
            }
        }
        if(AsepriteInstance::instance[1] == nullptr) {
            AsepriteInstance::instance[1] = new AsepriteInstance();
            std::vector<std::string> textureList = BasicConfigInstance::getData(ConfigType::BASIC)["TEXTURES"]["STATIC_OBSTACLES"];
            for (const auto &texture_path : textureList) {
                instance[1]->aseprite.emplace_back(AnimatedAsepriteConfig(texture_path));
            }
        }
        if(AsepriteInstance::instance[2] == nullptr) {
            AsepriteInstance::instance[2] = new AsepriteInstance();
            std::vector<std::string> textureList = BasicConfigInstance::getData(ConfigType::BASIC)["TEXTURES"]["BOAT"];
            for (const auto &texture_path : textureList) {
                instance[2]->aseprite.emplace_back(AnimatedAsepriteConfig(texture_path));
            }
        }
        if(AsepriteInstance::instance[3] == nullptr) {
            AsepriteInstance::instance[3] = new AsepriteInstance();
            std::vector<std::string> textureList = BasicConfigInstance::getData(ConfigType::BASIC)["TEXTURES"]["ANIMAL"];
            for (const auto &texture_path : textureList) {
                instance[3]->aseprite.emplace_back(AnimatedAsepriteConfig(texture_path));
            }
        }
}

Aseprite& AsepriteInstance::getAseprite(int instanceId, int &randIndex) {
    AsepriteInstance *instance = getInstance(instanceId);
    if(randIndex < 0 || randIndex > instance->aseprite.size() - 1) {
        randIndex = RandomNumber::getInstance().getRandomNumber(0, instance->aseprite.size() - 1);
        return instance->aseprite[randIndex].getAseprite();
    }
    return instance->aseprite[randIndex].getAseprite();

};

AsepriteInstance* AsepriteInstance::getInstance(int id) {
    std::lock_guard<std::mutex> lock(_mutex);
    return AsepriteInstance::instance[id];
}