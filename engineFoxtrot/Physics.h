#pragma once

#include "EventListener.h";
#include "EventManager.h";
#include "mObject.h";

class Physics : public EventListener {
private:
    EventManager* e;
    std::vector<mObject*>* objects;
public:
    Physics(EventManager* e, std::vector<mObject*>* objects) {
        this->e = e;
        this->objects = objects;
    }

    void update() {
        // Update every listener with new coordinates
        auto size = objects->size();
        // Logic for moving 
        for (std::vector<int>::size_type i = 0; i != size; i++) {
            int newX = 0;
            int newY = 0;

            objects->at(1)->setX(newX);
            objects->at(1)->setY(newY);

            // e->notify(MOVE, objects->at(i));


            bool onColl = true;
            if (onColl) {
                // Event will be created by game
                e->notify(EventType::COLLISION, objects->at(i));
            }
        }
        // logic on collision detection
    }

    void update(mObject* o) override {
        std::cout << "=====Physics!\n";
    }
};