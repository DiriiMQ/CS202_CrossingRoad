//
// Created by dirii on 8/12/23.
//

#ifndef CROSSING_ROAD_RANDOMNUMBER_H
#define CROSSING_ROAD_RANDOMNUMBER_H

#include <random>
#include <chrono>

class RandomNumber {
private:
    std::mt19937 rng;

    RandomNumber();

public:
    RandomNumber(const RandomNumber& other) = delete;
    RandomNumber& operator=(const RandomNumber& other) = delete;

    static RandomNumber& getInstance();
    int getRandomNumber(int min, int max);
};


#endif //CROSSING_ROAD_RANDOMNUMBER_H
