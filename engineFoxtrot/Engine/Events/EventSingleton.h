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

    void OnEvent(Event& e) {
        string name = e.GetName();
        if (handlers.count(name) > 0) {
            for (EventCallbackFn callback : handlers[name])
            {
                callback(e);
            }
        }
    }

#define REGISTER_PARSE_TYPE(X) template <> struct TypeParseTraits<X> \
        { static const char* name} ; const char* TypeParseTraits<X>::name = #X
    template<class Event>
    void setEventCallback(const EventCallbackFn& callback) {
        // Contains element 
        auto x = typeid(Event).name;
        if (handlers.at(T) > 0) {
            handlers.at(Event).push_back(callback);
        }
        // Create new vector
        else {
            auto ve = vector<const EventCallbackFn&>();
            ve.push_back(callback);
            handlers.insert(std::pair<string, std::vector<const EventCallbackFn&>>(name, ve));
        }

    }

private:
    map<string, vector<const EventCallbackFn&>> handlers;
    static EventSingleton instance;
    EventCallbackFn eventCallback;

    EventSingleton() {}
};

class TestSystem
{
public:
    TestSystem() {
        
    }
    ~TestSystem();

private:
    bool OnWindowClose(WindowCloseEvent& e) {
        return true;
    }
};

TestSystem::TestSystem()
{
}

TestSystem::~TestSystem()
{
}

