#pragma once
#include "MouseButtonEvent.h"

/// @brief
/// MouseButtonRealeasedEvent is triggered when left or right click is released. Derived class of MouseButtonEvent.
class MouseButtonReleasedEvent : public MouseButtonEvent
{
	MouseButtonReleasedEvent(MouseCode code) : MouseButtonEvent(code) {}
public:
	/// @brief
	/// MouseButtonReleasedEvent to string
	/// @return string with the realesed buton
	std::string ToString() const override
	{
		std::stringstream stream;
		stream << "MouseButtonReleased Event: " << button;
		auto string = stream.str();
		return string;
	}
};
