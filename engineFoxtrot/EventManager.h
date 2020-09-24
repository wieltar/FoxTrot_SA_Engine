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

    void subscribe(EventType eventType, EventListener* listener);
    void unsubscribe(EventType eventType, EventListener* listener);
    void notify(EventType eventType, Object* data);
};