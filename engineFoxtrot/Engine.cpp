#include "Engine.h"


Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::addEventListener(EventListener* listener, EventType t) {
    eventManager.subscribe(t, listener);
}