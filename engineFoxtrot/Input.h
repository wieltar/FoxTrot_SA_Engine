#pragma once

#include "EventListener.h";
#include "EventManager.h";
#include "Object.h";
#include <iostream>

class Input : public EventListener {
private:
    EventManager* e;
    std::vector<Object*>* objects;
public:
    Input(EventManager* e, std::vector<Object*>* objects) {
        this->e = e;
        this->objects = objects;
    }

    void runInput() {
        char ch;
        while (true) {
            ch = std::getchar();

            if (ch == 'a')
            {
                //this->e->notify(MOVE);
            }
        }
    }

    void update(Object* o) override {
        std::cout << "=====INPUT!\n";
    }
};