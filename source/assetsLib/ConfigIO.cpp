//
// Created by dirii on 1/11/23.
//

#include "ConfigIO.h"

#include <iostream>
#include <fstream>
#include <utility>

void ConfigIO::loadConfig(const char* path) {
    std::ifstream configFileStream(path);
    if (!configFileStream.is_open()) {
        std::cerr << "Cannot open config file" << std::endl;
        exit(1);
    }
    try {
        configFileStream >> this->config;
    } catch (json::parse_error &ex) {
        std::cerr << "Parse error at byte " << ex.byte << ": " << ex.what() << std::endl;
        exit(1);
    }
    configFileStream.close();
}

void ConfigIO::saveConfig(const char* path) {
    std::ofstream configFileStream(path);
    if (!configFileStream.is_open()) {
        std::cerr << "Cannot open config file" << std::endl;
        exit(1);
    }
//    std::cerr << "ConfigIO::saveConfig " << this->config["SCREEN"]["TEST"] << std::endl;
    configFileStream << std::setw(4) << this->config << std::endl;
    configFileStream.close();
}

json &ConfigIO::getConfig() {
    return this->config;
}

void ConfigIO::setConfig(json _config) {
    this->config = std::move(_config);
}

void BasicConfig::loadConfig() {
    ConfigIO::loadConfig(BASIC_CONFIG_PATH.c_str());
}

void BasicConfig::saveConfig() {
    ConfigIO::saveConfig(BASIC_CONFIG_PATH.c_str());
}

BasicConfig::~BasicConfig() {
    this->saveConfig();

    std::cout << "BasicConfig::~BasicConfig() called!" << std::endl;
}

BasicConfig::BasicConfig(std::string path) : BASIC_CONFIG_PATH(std::move(path)) {
    this->loadConfig();
}

BasicConfigInstance* BasicConfigInstance::instance = nullptr;
std::mutex BasicConfigInstance::_mutex;
BasicConfig BasicConfigInstance::config[2] = {
        BasicConfig("../assets/configs/basic.json"),
        BasicConfig("../assets/configs/leaderboard.json")
};

BasicConfigInstance &BasicConfigInstance::getInstance(int id) {
    std::lock_guard<std::mutex> lock(_mutex);
//    if (BasicConfigInstance::instance[id] == nullptr) {
//        instance = new BasicConfigInstance();
//    }
    return BasicConfigInstance::instance[id];
}

json &BasicConfigInstance::getData(int id) {
    return BasicConfigInstance::config[id].getConfig();
}

BasicConfig &BasicConfigInstance::getConfig(int id) {
    return BasicConfigInstance::config[id];
}

//void BasicConfigInstance::destroyInstance(int id = 0) {
//    std::lock_guard<std::mutex> lock(_mutex);
//    if (instance != nullptr) {
//        delete instance;
//        instance = nullptr;
//    }
//}

