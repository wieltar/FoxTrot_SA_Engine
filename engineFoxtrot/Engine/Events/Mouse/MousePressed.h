#pragma once
#include "MouseButtonEvent.h"
#include "Events/Codes/MouseCodes.h"
class MouseButtonPressed : public MouseButtonEvent
{
	MouseButtonPressed(const MouseCode code) : MouseButtonEvent(code) {}
public:
	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << button;
		auto string = ss.str();
		return string;
	}
};
