#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "mObject.h"
#include "EventManager.h"
#include "mPhysics.h"
#include "Input.h"
#include <chrono>
#include <thread>
#include "EventType.h"
#include "Video.h"

class mEngine {
private:
    std::vector<mObject*> objects = std::vector<mObject*>();
    EventManager manager = EventManager();

    mPhysics* physics;
    Input* inp;
    Video* video;
public:
    mEngine() {
        EventManager* e = &manager;
        std::vector<mObject*>* ob = &objects;

        physics = new mPhysics(e, ob);
        inp = new Input(e, ob);
        video = new Video(e, ob);

        manager.subscribe(EventType::MOVE, physics);
        manager.subscribe(EventType::MOVE, inp);
    }

    void addEventListener(EventListener* listener, EventType t) {
        manager.subscribe(t, listener);
    }

    void addObject(mObject* o) {
        objects.push_back(o);
    }

    void run() {
        // Wait user input
        std::thread([this] { this->inp->runInput(); }).detach();

        while (true) {
            // Update physics
            physics->update();
            // Update screen
            video->update();
            // Etc.

            std::cout << std::endl;
        }
    }
};