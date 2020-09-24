#include "EventManager.h"

void EventManager::subscribe(EventType t, EventListener* l) {
    // Contains element 
    if (listeners.count(t) > 0) {
        listeners.at(t).push_back(l);
    }
    // Create new vector
    else {
        // mymap.insert(pair<int, vector<int> > (10, {1, 2, 3}));
        listeners.insert(std::pair<EventType, std::vector<EventListener*>>(t, { l }));
    }
}

void EventManager::unsubscribe(EventType t, EventListener* l) {
    if (listeners.count(t) > 0) {
        auto itt = listeners.at(t);
        auto it = std::find(itt.begin(), itt.end(), l);
        itt.erase(it);
    }
}


void EventManager::notify(EventType t, Object* data) {
    if (listeners.count(t) > 0) {
        for (auto listeners : listeners.at(t))
            listeners->update(data);
    }
}