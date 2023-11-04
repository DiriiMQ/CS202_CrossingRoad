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
    ConfigIO::loadConfig(BASIC_CONFIG_PATH);
}

void BasicConfig::saveConfig() {
    ConfigIO::saveConfig(BASIC_CONFIG_PATH);
}

BasicConfig::BasicConfig() {
    this->loadConfig();
}

BasicConfig::~BasicConfig() {
    this->saveConfig();
}

BasicConfigInstance* BasicConfigInstance::instance = nullptr;
std::mutex BasicConfigInstance::_mutex;

BasicConfigInstance *BasicConfigInstance::getInstance() {
    std::lock_guard<std::mutex> lock(_mutex);
    if (instance == nullptr) {
        instance = new BasicConfigInstance();
    }
    return instance;
}

json &BasicConfigInstance::getData() {
    return this->config.getConfig();
}

BasicConfig &BasicConfigInstance::getConfig() {
    return this->config;
}

void BasicConfigInstance::destroyInstance() {
    std::lock_guard<std::mutex> lock(_mutex);
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

