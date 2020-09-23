#pragma once
#include "EventListener.h"
#include "EventManager.h"
#include "EventType.h"
#include "mObject.h"

class Video {
private:
    EventManager* e;
    std::vector<mObject*>* objects;
public:
    Video(EventManager* e, std::vector<mObject*>* objects) {
        this->e = e;
        this->objects = objects;
    }
    ~Video() {
        delete e;
        delete objects;
    }
    void update() {
        auto size = objects->size();
        // Logic for moving 
        for (std::vector<int>::size_type i = 0; i != size; i++) {
            // Draw
            objects->at(i)->draw();
        }
    }
};