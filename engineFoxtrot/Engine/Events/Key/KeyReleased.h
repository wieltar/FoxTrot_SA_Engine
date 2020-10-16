#pragma once
#include "KeyEvent.h"
class KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(KeyCode _keycode) : KeyEvent(_keycode) {}

	uint16_t GetRepeatCount() const { return repeatCount; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << keycode;
		return ss.str();
	}
};