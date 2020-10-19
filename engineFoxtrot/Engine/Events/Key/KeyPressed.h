#pragma once
#include "KeyEvent.h"

/// @brief
/// KeyPressedEvent is triggered when a key is released
class KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(KeyCode _keycode, const uint16_t _repeatCount) : KeyEvent(_keycode) {}

	/// @brief
	/// RepeatCount
	/// @return the times pressed
	uint16_t GetRepeatCount() const { return repeatCount; }

	/// @brief
	/// KeyReleasedEvent to string
	/// @return string with key code released
	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << keycode << " (" << repeatCount << " repeats)";
		return ss.str();
	}

private:
	uint16_t repeatCount;
};