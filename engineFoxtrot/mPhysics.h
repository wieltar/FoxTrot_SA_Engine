#pragma once

#include "EventListener.h"
#include "EventManager.h"
#include "EventType.h"
#include "mObject.h"

class mPhysics : public EventListener {
private:
    EventManager* e;
    std::vector<mObject*>* objects;
public:
    mPhysics(EventManager* e, std::vector<mObject*>* objects) {
        this->e = e;
        this->objects = objects;
    }
    ~mPhysics() {
        delete e;
        delete objects;
    }

    void update() {
        // Update every listener with new coordinates
        auto size = objects->size();
        // Logic for moving 
        for (std::vector<int>::size_type i = 0; i != size; i++) {
            auto objectPtr = objects->at(i);
            if (!objectPtr->getIsStatic()) {

                // Notify when a collision happend
                bool onColl = true;
                if (onColl) {
                    std::cout << "Notify collision" << std::endl;
                    e->notify(EventType::COLLISION, objects->at(i));
                }
            }
        }
        // logic on collision detection
    }

    void update(mObject* o) override {
        std::cout << "=====Physics!\n";
        // Move player
    }
};