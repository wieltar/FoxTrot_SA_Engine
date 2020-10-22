#pragma once
#include "Events/Event.h"

/// @brief
/// MouseMoved event is triggered when the mouse is moved. Derived class of Event.
class MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(const float _x, const float _y) : xPosition{ _x }, yPosition{ _y } {};

	/// @brief
	/// Gets the new X coords of the mouse relative to screen
	/// @return float new X 
	const float GetX() { return xPosition; }

	/// @brief
	/// Gets the new Y coords of the mouse relative to screen
	/// @return float new Y 
	const float GetY() { return yPosition; }

	/// @brief
	/// MouseButtonPressed to string
	/// @return string with the realesed button
	std::string ToString() const override
	{
		std::stringstream stream;
		stream << "MouseMovedEvent: " << xPosition << ", " << yPosition;
		return stream.str();
	}
private:
	const float xPosition, yPosition;
};
