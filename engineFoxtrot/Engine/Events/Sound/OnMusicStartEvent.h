#pragma once
#include "Events/Sound/BaseSoundEvent.h"


/// @brief
/// AppTickEvent is fired when a tick happened in the engine. Derived class of event. 
class OnMusicStartEvent : public BaseSoundEvent
{
	OnMusicStartEvent(const std::string& _file) : BaseSoundEvent(_file) {}

	/// @brief
	/// KeyReleasedEvent to string
	/// @return string with key code released
	std::string ToString() const override
	{
		std::stringstream stream;
		stream << "Started Sound: " << fileName ;
	}
};