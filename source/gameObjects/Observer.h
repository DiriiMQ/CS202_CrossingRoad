//
// Created by LENOVO on 11/16/2023.
//

#ifndef CROSSING_ROAD_OBSERVER_H
#define CROSSING_ROAD_OBSERVER_H
#include <iostream>
#include <string>


class IObserver {
public:
    virtual ~IObserver() {};
    virtual void Update(const std::string &message) = 0;
};

class ISubject {
public:
    virtual ~ISubject() {};
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};


#endif //CROSSING_ROAD_OBSERVER_H
