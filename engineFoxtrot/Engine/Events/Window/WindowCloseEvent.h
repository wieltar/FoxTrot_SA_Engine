#pragma once
#include "Events/Event.h"

/// @brief
/// WindowClosedEvent is fired when the window is closed. Derived class of event. 
class WindowCloseEvent : public Event
{
public:
	/// @brief
	/// WindowClosedEvent is fired when the window is closed. Derived class of event. 
	WindowCloseEvent() = default;

	/// @brief
	/// Returns the eventType of a specific event
	/// @return EventType
	EventType GetEventType() const override { return EventType::WindowClose; }
	
	/// @brief
	/// Get the name of an event
	/// @returns the name of the event
	const char* GetName() const override { return "Window close"; }
};