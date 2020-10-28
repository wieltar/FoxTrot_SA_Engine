#pragma once
#include "Event.h";
#include "core.h"
using EventCallbackFn = std::function<void(Event&)>;

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

class API EventSingleton
{
public:
    static EventSingleton& get_instance() { return instance; }

    // prohibit copy & move
    EventSingleton(const EventSingleton&) = delete;
    EventSingleton(EventSingleton&&) = delete;
    EventSingleton& operator=(const EventSingleton&) = delete;
    EventSingleton& operator=(EventSingleton&&) = delete;

    /// @brief
    /// OnEvent is triggered when an event is fired, and send message to all registered listiners
    /// @template T is fired
    /// @param Event the event that is fired with data
    /// @assert check wheter the type T and the Event fired is the same
    template<typename T>
    void dispatchEvent(Event& event) {
        static_assert(std::is_base_of<Event, T>::value, "dispatchEvent Assert fail: Make sure the event that is fired and the Template Type is the same");
        // Contains element 
        string typeName = typeid(T).name();
        if (handlers.count(typeName) > 0) {
            for (auto handler : handlers.at(typeName)) {
                handler(event);
            }
        }
    }

    /// @brief
    /// Register a callback for a specific Event. 
    /// @template T is fired
    /// @param EventCallbackFn& the method that should be executed when an event is fired
    /// @assert check wheter the type T and the Event fired is the same
    template<typename T>
    void setEventCallback(const EventCallbackFn& callback) {
        static_assert(std::is_base_of<Event, T>::value, "setEventCallback Assert fail: Make sure the event in the param of callback is the same as the Template Type");
        // Contains element 
        string typeName = typeid(T).name();
        if(handlers.count(typeName) > 0) { 
            handlers[typeName].push_back(callback);
        }
        // Create new vector
        else {
            handlers[typeName].push_back({ callback });
        }
    }

private:
    map<string, vector<function<void(Event&)>>> handlers = map<string, vector<function<void(Event&)>>>();
    static EventSingleton instance;

    EventSingleton() {}
};