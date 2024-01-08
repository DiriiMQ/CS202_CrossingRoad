//
// Created by DucAnh on 1/2/2024.
//

#ifndef CROSSING_ROAD_RANKINGSCREEN_H
#define CROSSING_ROAD_RANKINGSCREEN_H

#include "BaseScreen.h"
#include <vector>

class RankingScreen : public BaseScreen {
private:
    Texture2D background{};
    std::vector<int> scores;

    bool hasInit = false;

public:
    RankingScreen() = default;
    ~RankingScreen();
    void init();

    void handleInput() override;
    void update() override;
    void draw() override;

    void load() override;
    void unload() override;

    void setBackground(Texture2D _bg);
    static void resetRanking();
    static void addScore(int score);
};


#endif //CROSSING_ROAD_RANKINGSCREEN_H
