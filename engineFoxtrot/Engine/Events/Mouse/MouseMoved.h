#pragma once
#include "Events/Event.h"
class MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(const float _x, const float _y) : x{ _x }, y{ _y } {};
	const float GetX() { return x; }
	const float GetY() { return y; }
	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << x << ", " << y;
		auto string = ss.str();
		return string;
	}
private:
	const float x, y;
};
