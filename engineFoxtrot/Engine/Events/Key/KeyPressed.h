#pragma once
#include "KeyEvent.h"
class KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(KeyCode _keycode, const uint16_t _repeatCount) : KeyEvent(_keycode) {}

	uint16_t GetRepeatCount() const { return repeatCount; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << keycode << " (" << repeatCount << " repeats)";
		return ss.str();
	}

private:
	uint16_t repeatCount;
};