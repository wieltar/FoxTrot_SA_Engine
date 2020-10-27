#pragma once
#include "Events/Event.h"
#include "./SceneManager/Object.h"

/// @brief
/// AppTickEvent is fired when a tick happened in the engine. Derived class of event. 
class OnCollisionEvent : public Event
{
public:
	OnCollisionEvent(int _objectOneId, int _objectTwoId) : objectOneId{ _objectOneId }, objectTwoId{ _objectTwoId } {};

	int GetObjectOneId() const { return objectOneId; }
	int GetObjectTwoId() const { return objectTwoId; }
	/// @brief
	/// Returns the eventType of a specific event
	/// @return EventType
	EventType GetEventType() const override { return EventType::Action; }
	/// @brief
	/// Returns the name of the event
	virtual const char* GetName() const override = 0;
protected:
	int objectOneId;
	int objectTwoId;
};

class OnCollisionEndEvent : public OnCollisionEvent {
public:
	OnCollisionEndEvent(int _objectOneId, int _objectTwoId) : OnCollisionEvent(_objectOneId, _objectTwoId) {};
	virtual const char* GetName() const override { return "Collision end Event"; }
};

class OnCollisionBeginEvent : public OnCollisionEvent {
public:
	OnCollisionBeginEvent(int _objectOneId, int _objectTwoId) : OnCollisionEvent(_objectOneId, _objectTwoId) {};
	virtual const char* GetName() const override { return "Collision begin Event"; }
};