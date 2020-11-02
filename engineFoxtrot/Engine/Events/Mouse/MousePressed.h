#pragma once
#include "MouseButtonEvent.h"
#include "Events/Codes/MouseCodes.h"

/// @brief
/// MouseButtonPressedEvent is triggerd when a mouse button is pressed.  Derived class of MouseButtonEvent.
class MouseButtonPressed : public MouseButtonEvent
{
	MouseButtonPressed(const MouseCode code) : MouseButtonEvent(code) {}
public:
	/// @brief
	/// MouseButtonPressed to string
	/// @return string with the realesed button
	string ToString() const override
	{
		stringstream stream;
		stream << "MouseButtonPressedEvent: " << button;
		auto string = stream.str();
		return string;
	}
};
