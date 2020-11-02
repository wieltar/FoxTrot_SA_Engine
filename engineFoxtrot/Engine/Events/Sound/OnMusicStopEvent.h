#pragma once
#include "Events/Sound/BaseSoundEvent.h"


/// @brief
/// AppTickEvent is fired when a tick happened in the engine. Derived class of event. 
class OnMusicStopEvent : public BaseSoundEvent
{
public:
	OnMusicStopEvent(const std::string& _file) : BaseSoundEvent(_file) {}

	/// @brief
	/// KeyReleasedEvent to string
	/// @return string with key code released
	std::string ToString() const override
	{
		std::stringstream stream;
		stream << "Stop Sound: " << identifier;
		return stream.str();
	}

	/// @brief
	/// Returns the eventType of a specific event
	/// @return EventType
	EventType GetEventType() const override { return EventType::OnMusicStopEvent; }
	/// @brief
	/// Returns the name of the event
	const char* GetName() const override { return "Action Sound Stop Event"; }
};