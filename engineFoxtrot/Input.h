#pragma once

#include "EventListener.h"
#include "EventManager.h"
#include "mObject.h"
#include <iostream>
#include "KeyEvent.h"

class Input : public EventListener {
private:
    EventManager* e;
    std::vector<mObject*>* objects;
public:
    Input(EventManager* e, std::vector<mObject*>* objects) {
        this->e = e;
        this->objects = objects;
    }

    void runInput() {
        int ch;
        while (true) {
            ch = std::getchar();

            
        }
    }

    void update(mObject* o) override {
        std::cout << "=====INPUT!\n";
    }
};