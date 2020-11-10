#pragma once
#include "Events/Sound/BaseSoundEvent.h"


/// @brief
/// AppTickEvent is fired when a tick happened in the engine. Derived class of event. 
class SoundAttachEvent : public BaseSoundEvent
{
public:
	SoundAttachEvent(const std::string& identifier, const std::string& _file) : BaseSoundEvent(identifier), fileName(_file) {}

	/// @brief
	/// KeyCode that is pressed
	/// @returns KeyCode
	const std::string& GetFileName() { return fileName; }


	/// @brief
	/// KeyReleasedEvent to string
	/// @return string with key code released
	std::string ToString() const override
	{
		std::stringstream stream;
		stream << "Attach Sound: " << fileName << " with identifier " << identifier;
		return stream.str();
	}

	/// @brief
	/// Returns the eventType of a specific event
	/// @return EventType
	EventType GetEventType() const override { return EventType::AttachSound; }
	/// @brief
	/// Returns the name of the event
	const char* GetName() const override { return "Attach Sound Event"; }
protected:
	const std::string& fileName;
};