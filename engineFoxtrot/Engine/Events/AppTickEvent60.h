#pragma once
#include "Events/Event.h"

/// @brief
/// AppTickEvent is fired when a tick happened in the engine. Derived class of event. 
class AppTickEvent60 : public Event
{
public:
	AppTickEvent60() = default;

	/// @brief
	/// Returns the eventType of a specific event
	/// @return EventType
	EventType GetEventType() const override { return EventType::Engine60; }
	/// @brief
	/// Returns the name of the event
	const char* GetName() const override { return "App tick event 60"; }
};