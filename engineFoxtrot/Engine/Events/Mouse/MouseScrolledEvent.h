#pragma once
#include "Events/Event.h"

/// @brief
/// MouseMoved event is triggered when the mousewheel is scrolled. Derived class of Event.
class MouseScrolledEvent : public Event
{
public:
	MouseScrolledEvent(const float xOffset, const float yOffset)
		: m_XOffset(xOffset), m_YOffset(yOffset) {}

	/// @brief
	/// Gets the new X coords of the mouse relative to screen
	/// @return float new X 
	float GetXOffset() const { return m_XOffset; }

	/// @brief
	/// Gets the new Y coords of the mouse relative to screen
	/// @return float new Y 
	float GetYOffset() const { return m_YOffset; }

	/// @brief
	/// MouseScrolledEvent to string
	/// @return string with the new X and Y coords
	string ToString() const override
	{
		stringstream stream;
		stream << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
		return stream.str();
	}	
private:
	float m_XOffset, m_YOffset;
};
