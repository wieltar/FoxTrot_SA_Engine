#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "EventType.h"
#include "EventListener.h"
#include "mObject.h"

class EventManager {
private:
    std::map<EventType, std::vector<EventListener*>*> listeners = std::map<EventType, std::vector<EventListener*>*>();
public:
    EventManager() { }

    void subscribe(EventType t, EventListener* l) {
        // Contains element 
        if (listeners.count(t) > 0) {
            listeners.find(t)->second->push_back(l);
        }
        // Create new vector
        else {
            std::vector<EventListener*>* x = new std::vector<EventListener*>();
            x->push_back(l);
            listeners.insert(std::pair<EventType, std::vector<EventListener*>*>(t, x));
        }
    }

    void unsubscribe(EventType t, EventListener* l) {
        if (listeners.count(t) > 0) {
            auto itt = listeners.find(t)->second;
            auto it = std::find(itt->begin(), itt->end(), l);
            itt->erase(it);
        }
    }

    void notify(EventType t, mObject* data) {
        if (listeners.count(t) > 0) {
            auto size = listeners.find(t)->second->size();
            auto vec = listeners.find(t)->second;
            for (std::vector<int>::size_type i = 0; i != size; i++) {
                vec->at(i)->update(data);
            }
        }
    }
};