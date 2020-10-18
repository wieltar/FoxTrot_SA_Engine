#pragma once

#include "EventType.h"
#include "EventListener.h"
#include "../../SceneManager/Object.h"

#if(EXPORT)
class DLLEXPORT EventManager
#else
class EventManager 
#endif
{
private:
    std::map<const OldEventType, std::vector<EventListener*>> listeners = std::map<const OldEventType, std::vector<EventListener*>>();
public:
    EventManager() { }

    void subscribe(const OldEventType eventType, EventListener* listener);
    void unsubscribe(const OldEventType eventType, EventListener* listener);
    void notify(const OldEventType eventType, Object* data);
};