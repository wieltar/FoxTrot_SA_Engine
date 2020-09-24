#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "EventType.h"
#include "EventListener.h"
#include "Object.h"

class EventManager {
private:
    std::map<EventType, std::vector<EventListener*>> listeners = std::map<EventType, std::vector<EventListener*>>();
public:
    EventManager() { }

    void subscribe(EventType t, EventListener* l) {
        // Contains element 
        if (listeners.count(t) > 0) {
            listeners.at(t).push_back(l);
        }
        // Create new vector
        else {
            // mymap.insert(pair<int, vector<int> > (10, {1, 2, 3}));
            listeners.insert(pair<EventType, vector<EventListener*>>(t, { l }));
        }
    }

    void unsubscribe(EventType t, EventListener* l) {
        if (listeners.count(t) > 0) {
            auto itt = listeners.at(t);
            auto it = std::find(itt.begin(), itt.end(), l);
            itt.erase(it);
        }
    }

    void notify(EventType t, Object* data) {
        if (listeners.count(t) > 0) {
            for (auto listeners : listeners.at(t)) 
                listeners->update(data);
        }
    }
};