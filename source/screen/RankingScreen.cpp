//
// Created by DucAnh on 1/2/2024.
//

#include "RankingScreen.h"
#include "assetsLib/ConfigIO.h"
#include <string>

void RankingScreen::init() {
    this->background = LoadTexture(
            BasicConfigInstance::getData()["BACKGROUND"]["LEADERBOARD"].get<std::string>().c_str()
    );
}

void RankingScreen::load() {
    BaseScreen::load();

    if (!this->hasInit) {
        this->init();
        this->hasInit = true;
    }
}

void RankingScreen::unload() {
    BaseScreen::unload();
}

RankingScreen::~RankingScreen() {
    UnloadTexture(this->background);
}

void RankingScreen::setBackground(Texture2D _bg) {
    this->background = _bg;
}

void RankingScreen::handleInput() {

}

void RankingScreen::update() {
    this->scores = BasicConfigInstance::getData(
            ConfigType::LEADERBOARD
            )["SCORES"].get<std::vector<int>>();
}

void RankingScreen::draw() {
    DrawTexture(this->background, 0, 0, WHITE);

    Rectangle backButtonRect = {
            1060,
            680,
            250,
            50
    };
    if(GuiButtonRounded(backButtonRect, "Back")) {
        screenManager->backScreen();
    }

    for (int i = 0; i < std::min(3, (int)this->scores.size()); i++) {
        DrawText(
                std::to_string(this->scores[i]).c_str(),
                700,
                240 + i * 155,
                100,
                ORANGE
                );
    }

    Rectangle resetButtonRect = {
            80,
            680,
            250,
            50
    };
    if(GuiButtonRounded(resetButtonRect, "Reset")) {
        BasicConfigInstance::getData(ConfigType::LEADERBOARD)["SCORES"] = std::vector<int>();

    }
}

void RankingScreen::resetRanking() {
    BasicConfigInstance::getData(ConfigType::LEADERBOARD)["SCORES"] = std::vector<int>();
}

void RankingScreen::addScore(int score) {
    std::vector<int> scores = BasicConfigInstance::getData(ConfigType::LEADERBOARD)["SCORES"].get<std::vector<int>>();
    scores.push_back(score);
    std::sort(scores.begin(), scores.end(), std::greater<int>());
    BasicConfigInstance::getData(ConfigType::LEADERBOARD)["SCORES"] = scores;
}
