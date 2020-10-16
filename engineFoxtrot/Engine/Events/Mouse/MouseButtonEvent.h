#pragma once
#include "Events/Event.h"
#include "Events/Codes/MouseCodes.h"
class MouseButtonEvent : public Event
{
public:
	const MouseCode GetButton() { return button; }
	MouseButtonEvent(const MouseCode _button) : button{ _button } {};

protected:
	MouseCode button;
};
