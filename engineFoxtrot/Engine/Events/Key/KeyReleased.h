#pragma once
#include "KeyEvent.h"


/// @brief
/// KeyReleasedEvent is triggered when a key is typed
class KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(KeyCode _keycode) : KeyEvent(_keycode) {}

	/// @brief
	/// KeyReleasedEvent to string
	/// @return string with key code released
	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << keycode;
		return ss.str();
	}
private:
};