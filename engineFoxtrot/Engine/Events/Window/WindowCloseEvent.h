#pragma once
#include "Events/Event.h"
class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;


	EventType GetEventType() const override { return EventType::WindowClose; }
	const char* GetName() const override { return "Window close"; }

	std::string WindowClosedSpecific() { return "Window closed specific method"; };
};