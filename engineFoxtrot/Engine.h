#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Object.h"
#include "EventManager.h"
#include "mPhysics.h"
#include "Input.h"
#include <thread>
#include <iostream>
#include <chrono>
#include <thread>

class Engine {
private:
    std::vector<mObject*> objects = std::vector<mObject*>();
    EventManager manager = EventManager();

    mPhysics* p;
    Input* i;
public:
    Engine() {
        EventManager* e = &manager;
        std::vector<mObject*>* ob = &objects;

        p = new mPhysics(e, ob);
        i = new Input(e, ob);

        manager.subscribe(EventType::MOVE, p);
        manager.subscribe(EventType::MOVE, i);
    }

    void registerEventListener(EventType t, EventListener* l) {
        manager.subscribe(t, l);
    }

    void addObject(mObject* o) {
        objects.push_back(o);
    }

    std::vector<mObject*>* getObj() {
        return &this->objects;
    }

    void input() {
        i->runInput();
    }

    void run() {
        //std::thread([this] { this->input(); }).detach();

        while (true) {
            // Update physics
            p->update();
            // Wait user input

            // Update screen
        //video->update();
            // Etc.
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
};