#include "glpch.h"

#include "EventManager.h"

void EventManager::subscribe(EventType eventType, EventListener* listener) {
    // Contains element 
    if (listeners.count(eventType) > 0) {
        listeners.at(eventType).push_back(listener);
    }
    // Create new vector
    else {
        listeners.insert(std::pair<EventType, std::vector<EventListener*>>(eventType, { listener }));
    }
}

void EventManager::unsubscribe(EventType eventType, EventListener* listener) {
    if (listeners.count(eventType) > 0) {
        auto itt = listeners.at(eventType);
        auto it = std::find(itt.begin(), itt.end(), listener);
        itt.erase(it);
    }
}


void EventManager::notify(EventType eventType, Object* data) {
    if (listeners.count(eventType) > 0) {
        for (auto listeners : listeners.at(eventType))
            listeners->update(data);
    }
}