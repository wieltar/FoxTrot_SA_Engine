#include "Engine.h"


Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::addEventListener(EventListener* listener, EventType eventType) {
    eventManager.subscribe(eventType, listener);
}