#pragma once
#include "KeyEvent.h"

/// @brief
/// KeyPressedEvent is triggered when a key is released
class KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(KeyCode _keycode, const uint16_t _repeatCount) : KeyEvent(_keycode), repeatCount(_repeatCount) {}

	/// @brief
	/// RepeatCount
	/// @return the times pressed
	uint16_t GetRepeatCount() const { return repeatCount; }

	/// @brief
	/// KeyReleasedEvent to string
	/// @return string with key code released
	string ToString() const override
	{
		stringstream stream;
		stream << "KeyPressedEvent: " << (int)keycode << " (" << repeatCount << " repeats)";
		return stream.str();
	}

private:
	uint16_t repeatCount = 0;
};