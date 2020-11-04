#pragma once
#include "Events/Event.h"

/// @brief
/// An event fired when the user toggles the fps counter using the set button
class FpsToggleEvent : public Event
{
public:
	FpsToggleEvent() {}

	/// @brief
	/// Returns the eventType of a specific event
	/// @return EventType
	EventType GetEventType() const override { return EventType::Action; }
	/// @brief
	/// Returns the name of the event
	const char* GetName() const override { return "Fps toggle"; }
};