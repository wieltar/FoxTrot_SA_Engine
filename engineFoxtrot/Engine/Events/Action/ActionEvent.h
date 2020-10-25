#pragma once
#include "Events/Event.h"


enum class Direction {
	UP_RIGHT,
	UP_LEFT,
	UP,
	RIGHT,
	LEFT
};

/// @brief
/// AppTickEvent is fired when a tick happened in the engine. Derived class of event. 
class ActionEvent : public Event
{
public:
	ActionEvent(const Direction _direction, int _objectId) : direction{ _direction }, objectId{ _objectId } {};

	Direction GetDirection() const { return direction; }
	int GetObjectId() const { return objectId; }
	/// @brief
	/// Returns the eventType of a specific event
	/// @return EventType
	EventType GetEventType() const override { return EventType::Action; }
	/// @brief
	/// Returns the name of the event
	const char* GetName() const override { return "Action Event"; }
private:
	int objectId;
	Direction direction;
};