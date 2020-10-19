#pragma once
#include "Events/Event.h"

class AppTickEvent : public Event
{
public:
	AppTickEvent() = default;


	EventType GetEventType() const override { return EventType::Engine60; }
	const char* GetName() const override { return "App tick event"; }
};