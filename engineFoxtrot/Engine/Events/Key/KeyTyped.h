#pragma once
#include "KeyEvent.h"
class KeyTypedEvent : public KeyEvent
{
public:
	KeyTypedEvent(KeyCode _keycode) : KeyEvent(_keycode) {}


	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyTypedEvent: " << keycode;
		return ss.str();
	}
};