#include "EventManager.h"

/// @brief a subscribe function for all other classes
/// @param eventType
/// @param listener
void EventManager::subscribe(const EventType eventType, EventListener* listener) {
    // Contains element 
    if (listeners.count(eventType) > 0) {
        listeners.at(eventType).push_back(listener);
    }
    // Create new vector
    else {
        listeners.insert(std::pair<EventType, std::vector<EventListener*>>(eventType, { listener }));
    }
}
/// @brief a unsubscribe function for all other classes
/// @param eventType
/// @param listener
void EventManager::unsubscribe(const EventType eventType, EventListener* listener) {
    if (listeners.count(eventType) > 0) {
        auto itt = listeners.at(eventType);
        auto it = std::find(itt.begin(), itt.end(), listener);
        itt.erase(it);
    }
}

/// @brief a notify function for other classes so they can notify events
/// @param eventType
/// @param data
void EventManager::notify(const EventType eventType, Object* data) {
    if (listeners.count(eventType) > 0) {
        for (auto listeners : listeners.at(eventType))
            listeners->update(data);
    }
}