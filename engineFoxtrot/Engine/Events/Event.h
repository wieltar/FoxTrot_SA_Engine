#pragma once
#include "stdafx.h"
#include "Events/EventType.h"
class Event
{
public:
	virtual ~Event() = default;

	bool Handled = false;

	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const = 0;
	virtual std::string ToString() const { return GetName(); }
};

inline std::ostream& operator<<(std::ostream& os, const Event& e)
{
	return os << e.ToString();
}
