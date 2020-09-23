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
    Input* input;
    Video* video;
public:
    mEngine() {
        physics = new mPhysics(&manager, &objects);
        input = new Input(&manager, &objects);
        video = new Video(&manager, &objects);

        // TODO event categorien toevoegen en registratie afhandelen in automatische loop?
        manager.subscribe(EventType::MOVE, physics);
        manager.subscribe(EventType::MOVE, input);
    }

    ~mEngine() {
        delete physics;
        delete input;
        delete video;
    }

    void addEventListener(EventListener* listener, EventType t) {
        manager.subscribe(t, listener);
    }

    void registerGameObject(mObject* o) {
        objects.push_back(o);
    }

    void run() {
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