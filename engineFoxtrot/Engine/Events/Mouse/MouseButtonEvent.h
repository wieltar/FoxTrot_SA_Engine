#pragma once
#include "Events/Event.h"
#include "Events/Codes/MouseCodes.h"

/// @brief
/// Base class for all mouse buttons events
class MouseButtonEvent : public Event
{
public:
	MouseButtonEvent(const MouseCode _button) : button{ _button } {};
	
	/// /// @brief
	/// GetButton that is pressed on the mouse
	/// @return the MouseCode enum
	const MouseCode GetButton() { return button; }
protected:
	MouseCode button;
};
