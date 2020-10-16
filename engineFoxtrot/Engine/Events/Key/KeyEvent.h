#pragma once
#include "Events/Event.h"
#include <Events\Codes\KeyCodes.h>
class KeyEvent : public Event
{
public:

	KeyCode GetKeyCode() const { return keycode; }
protected:
	KeyEvent(const KeyCode _keyCode) : keycode{ _keyCode } {};
	KeyCode keycode;
};
