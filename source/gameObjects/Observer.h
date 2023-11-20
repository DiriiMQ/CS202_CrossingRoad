//
// Created by LENOVO on 11/16/2023.
//

#ifndef CROSSING_ROAD_OBSERVER_H
#define CROSSING_ROAD_OBSERVER_H
#include <iostream>
#include <string>
#include "Message.h"

class IObserver {
public:
    virtual ~IObserver() {};
    virtual void updateMessage(const Message message) = 0;
};

class ISubject {
public:
    virtual ~ISubject() {};
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify(Message mesage) = 0;
};


#endif //CROSSING_ROAD_OBSERVER_H
