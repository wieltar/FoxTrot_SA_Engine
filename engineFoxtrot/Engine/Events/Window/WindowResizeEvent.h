#pragma once
#include "Events/Event.h"
class WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(int width, int height)
		: m_Width(width), m_Height(height) {}

	uint32_t GetWidth() const { return m_Width; }
	uint32_t GetHeight() const { return m_Height; }

	EventType GetEventType() const override { return EventType::WindowClose; }
	const char* GetName() const override { return "Window close"; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
		return ss.str();
	}
private:
	unsigned int m_Width, m_Height;
};