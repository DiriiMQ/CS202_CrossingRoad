//
// Created by dirii on 1/11/23.
//

#ifndef CROSSING_ROAD_CONFIGIO_H
#define CROSSING_ROAD_CONFIGIO_H

#include "nlohmann/json.hpp"
#include <mutex>

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
public:
    static constexpr char BASIC_CONFIG_PATH[] = "../assets/configs/basic.json";

    BasicConfig();
    ~BasicConfig();

    void loadConfig();
    void saveConfig();
};

class BasicConfigInstance {
private:
    static BasicConfigInstance *instance;
    static std::mutex _mutex;
    
protected:
    BasicConfigInstance() = default;
    ~BasicConfigInstance() = default;
    BasicConfig config;

public:
    BasicConfigInstance(const BasicConfigInstance&) = delete;
    BasicConfigInstance& operator=(const BasicConfigInstance&) = delete;
    
    static BasicConfigInstance *getInstance();
    static void destroyInstance();
    json& getData();
    BasicConfig& getConfig();
};

#endif //CROSSING_ROAD_CONFIGIO_H
