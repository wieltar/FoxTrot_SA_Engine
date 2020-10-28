#pragma once
#include <ostream>
#include "EventType.h"

/// @brief
	/// Abstract event class. Multiple events have this class as a super class
class Event
{
public:
	virtual ~Event() = default;

	bool Handled = false;
	/// @brief
	/// Returns the eventType of a specific event
	/// @return EventType
	virtual EventType GetEventType() const = 0;
	/// @brief
	/// Returns the name of a specific event
	virtual const char* GetName() const = 0;

	/// @brief
	/// Returns the name of the event
	virtual std::string ToString() const { return GetName(); }
};

inline std::ostream& operator<<(std::ostream& osStream, const Event& event)
{
	return osStream << event.ToString();
}
