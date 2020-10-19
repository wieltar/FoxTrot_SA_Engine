#pragma once
#include "Events/Window/WindowCloseEvent.h"
#include <functional>
#include <type_traits>

using EventCallbackFn = std::function<void(Event&)>;

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

class EventSingleton
{
public:
    static EventSingleton& get_instance() { return instance; }

    // prohibit copy & move
    EventSingleton(const EventSingleton&) = delete;
    EventSingleton(EventSingleton&&) = delete;
    EventSingleton& operator=(const EventSingleton&) = delete;
    EventSingleton& operator=(EventSingleton&&) = delete;

    std::string message() const { return "Hello, world!"; }

    template<typename T>
    void OnEvent(Event& e) {
        static_assert(std::is_base_of<Event, T>::value, "nee");
        // Contains element 
        string typeName = typeid(T).name();
        if (handlers.count(typeName) > 0) {
            for (auto handler : handlers.at(typeName)) {
                handler(e);
            }
        }
    }

    template<typename T>
    void setEventCallback(const EventCallbackFn& callback) {
        static_assert(std::is_base_of<Event, T>::value, "wat doe je me aan?");
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