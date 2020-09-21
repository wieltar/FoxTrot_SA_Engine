#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Object.h"
#include "EventManager.h"
#include "Physics.h"
#include "Input.h"

class Engine {
private:
    std::vector<Object*> objects = std::vector<Object*>();
    EventManager manager = EventManager();

    Physics* p;
    Input* i;
public:
    Engine() {
        EventManager* e = &manager;
        std::vector<Object*>* ob = &objects;
        
        p = new Physics(e, ob);
        i = new Input(e, ob);

        manager.subscribe(MOVE, p);
        manager.subscribe(MOVE, i);
    }

    void addObject(Object* o) {
        objects.push_back(o);
    }

    std::vector<Object*>* getObj() {
        return &this->objects;
    }

    void run() {
        while (true) {
                // Update physics
            p->update();
                // Wait user input

                // Update screen
            //video->update();
                // Etc.
        }
    }
};