#pragma once
#include "Events/Window/WindowCloseEvent.h"
#include <functional>
#include <type_traits>


using EventCallbackFn = std::function<void(Event&)>;

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
    void OnEvent() {
        // Contains element 
        string typeName = typeid(T).name();
        if (handlers.count(typeName) > 0) {
            for (auto handler : handlers.at(typeName)) {
                std::function<void()> func = handler;
                func();
            }
        }
    }

    template<typename T>
    void setEventCallback(function<void()> callback) {
        // Contains element 
        string typeName = typeid(T).name();
        if(handlers.count(typeName) > 0) { //.at(typeName).empty()) {
            handlers[typeName].push_back(callback);
        }
        // Create new vector
        else {
            handlers[typeName].push_back({ callback });
        }
    }

    map<string, vector<function<void()>>> handlers = map<string, vector<function<void()>>>();
private:
    
    static EventSingleton instance;

    EventSingleton() {}
};