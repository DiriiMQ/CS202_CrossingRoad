//
// Created by dirii on 8/12/23.
//

#include "RandomNumber.h"

RandomNumber::RandomNumber() {
    rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
}

RandomNumber &RandomNumber::getInstance() {
    static RandomNumber instance;
    return instance;
}

int RandomNumber::getRandomNumber(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(this->rng);
}

// RandomNumber::getInstance().getRandomNumber(0, 100)