#pragma once
#include "MouseButtonEvent.h"
class MouseButtonReleasedEvent : public MouseButtonEvent
{
	MouseButtonReleasedEvent(MouseCode code) : MouseButtonEvent(code) {}
public:
	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonReleased Event: " << button;
		auto string = ss.str();
		return string;
	}
};
