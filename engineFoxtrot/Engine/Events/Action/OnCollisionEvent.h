#pragma once
#include "Events/Event.h"
#include "Events/Action/ActionEvent.h"
#include "./SceneManager/Object.h"

/// @brief
/// AppTickEvent is fired when a tick happened in the engine. Derived class of event. 
class OnCollisionEvent : public Event
{
public:
	OnCollisionEvent(int _objectOneId, int _objectTwoId, const std::map<int, Direction> _directionMap) : 
		objectOneId{ _objectOneId }, 
		objectTwoId{ _objectTwoId }, 
		directionMap{ _directionMap }{};

	int GetObjectOneId() const { return objectOneId; }
	int GetObjectTwoId() const { return objectTwoId; }
	/// @brief
	/// Returns the eventType of a specific event
	/// @return EventType
	EventType GetEventType() const override { return EventType::Action; }
	/// @brief
	/// Returns the name of the event
	virtual const char* GetName() const override = 0;

	std::map<int, Direction> getDirectionMap() { return directionMap; };
protected:
	int objectOneId;
	int objectTwoId;
	std::map<int, Direction> directionMap;
};

class OnCollisionEndEvent : public OnCollisionEvent {
public:
	OnCollisionEndEvent(int _objectOneId, int _objectTwoId, const std::map<int, Direction> _directionMap)
		: OnCollisionEvent(_objectOneId, _objectTwoId, _directionMap) {};
	virtual const char* GetName() const override { return "Collision end Event"; }
};

class OnCollisionBeginEvent : public OnCollisionEvent {
public:
	OnCollisionBeginEvent(int _objectOneId, int _objectTwoId, const std::map<int, Direction> _directionMap)
		: OnCollisionEvent(_objectOneId, _objectTwoId, _directionMap) {};
	virtual const char* GetName() const override { return "Collision begin Event"; }
};