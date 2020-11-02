#pragma once
#include "Events/Sound/BaseSoundEvent.h"


/// @brief
/// AppTickEvent is fired when a tick happened in the engine. Derived class of event. 
class OnMusicStartEvent : public BaseSoundEvent
{
public:
	OnMusicStartEvent(const std::string& identifier) : BaseSoundEvent(identifier) {}

	/// @brief
	/// KeyReleasedEvent to string
	/// @return string with key code released
	std::string ToString() const override
	{
		std::stringstream stream;
		stream << "Started Sound: " << identifier;
		return stream.str();
	}

	/// @brief
	/// Returns the eventType of a specific event
	/// @return EventType
	EventType GetEventType() const override { return EventType::OnMusicStartEvent; }
	/// @brief
	/// Returns the name of the event
	const char* GetName() const override { return "Action Sound Start Event"; }
};