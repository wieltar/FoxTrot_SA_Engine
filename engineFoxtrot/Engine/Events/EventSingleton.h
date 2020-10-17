#pragma once
#include "Events/Window/WindowCloseEvent.h"
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

    template<typename T, typename F>
    void OnEvent(const F& func) {
        EventDispatcher dispatcher;
        dispatcher.Dispatch<T>(BIND_EVENT_FN(func))
    }
    template<typename T>
    void OnEvent(T e) {
        inline constexpr bool is_base_of_v = is_base_of<Event, T>::value;
        if (is_base_of_v)
        {
            string typeName = typeid(T).name();
            if (! handlers.at(typeName).empty()) {
                for (EventCallbackFn callback : handlers[name])
                {
                    callback(e);
                }
            }
        }
    }


    template<typename T>
    void setEventCallback(const EventCallbackFn& callback) {
        // Contains element 
        string typeName = typeid(T).name();
        if (! handlers.at(typeName).empty()) {
            handlers[typeName].push_back(callback);
        }
        // Create new vector
        else {
            auto ve = vector<const EventCallbackFn&>();
            ve.push_back(callback);
            handlers[typeName].push_back(callback);
            //handlers.insert(std::pair<string, std::vector<const EventCallbackFn&>>(typename, ve));
        }

    }

private:
    map<string, vector<const EventCallbackFn&>> handlers;
    static EventSingleton instance;
    EventCallbackFn eventCallback;

    EventSingleton() {}
};