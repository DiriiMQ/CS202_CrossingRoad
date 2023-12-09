//
// Created by dirii on 1/11/23.
//

#ifndef CROSSING_ROAD_CONFIGIO_H
#define CROSSING_ROAD_CONFIGIO_H

#include "nlohmann/json.hpp"
#include <mutex>
#include <utility>

using json = nlohmann::json;

class ConfigIO {
private:
    json config;

public:
    ConfigIO() = default;
    ~ConfigIO() = default;

    void loadConfig(const char* path);
    void saveConfig(const char* path);

    json& getConfig();
    void setConfig(json config);
};

class BasicConfig : public ConfigIO {
private:
    std::string BASIC_CONFIG_PATH = "../assets/configs/basic.json";

public:
    BasicConfig() = default;
    explicit BasicConfig(std::string path);
    ~BasicConfig();

    void loadConfig();
    void saveConfig();
};

namespace ConfigType {
    enum ConfigType {
        BASIC,
        LEADERBOARD
    };
}

class BasicConfigInstance {
private:
    static BasicConfigInstance *instance;
    static std::mutex _mutex;
    static BasicConfig config[2];
    
protected:
    BasicConfigInstance() = default;
    ~BasicConfigInstance() = default;

public:
    BasicConfigInstance(const BasicConfigInstance&) = delete;
    BasicConfigInstance& operator=(const BasicConfigInstance&) = delete;
    
    static BasicConfigInstance &getInstance(int id = 0);
//    static void destroyInstance(int id);
    static json& getData(int id = 0);
    static BasicConfig& getConfig(int id = 0);
    static void reloadConfig(int id = 0);
};

#endif //CROSSING_ROAD_CONFIGIO_H
