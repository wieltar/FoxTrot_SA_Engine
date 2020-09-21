#pragma once

#include "EventListener.h";
#include "EventManager.h";
#include "Object.h";

class Physics : public EventListener {
private:
    EventManager* e;
    std::vector<Object*>* objects;
public:
    Physics(EventManager* e, std::vector<Object*>* objects) {
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

            objects->at(1)->X = newX;
            objects->at(1)->X = newY;

            e->notify(MOVE, objects->at(i));
        }
        // logic on collision detection

        // e->notify(MOVE, objects->at(10));
    }

    void update(Object* o) override {
        std::cout << "=====Physics!\n";
        std::cout << o->get_name() << std::endl;
    }
};