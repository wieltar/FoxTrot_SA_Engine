#pragma once
#include "Events/Event.h"
#include "Events/Action/ActionEvent.h"
#include "SceneManager/Object.h"

/// @brief
/// OnCollisionEvent base class of CollisionEnd and CollisionStart
class OnCollisionEvent : public Event
{
public:
	OnCollisionEvent(int _objectOneId, int _objectTwoId, const map<int, vector<Direction>> _directionMap) : 
		objectOneId{ _objectOneId }, 
		objectTwoId{ _objectTwoId }, 
		directionMap{ _directionMap }{};

	/// @brief
	/// The id of one of the objects where collision happend
	int GetObjectOneId() const { return objectOneId; }
	/// @brief
	/// The id of one of the objects where collision happend
	int GetObjectTwoId() const { return objectTwoId; }
	/// @brief
	/// Returns the eventType of a specific event
	/// @return EventType
	virtual EventType GetEventType() const override = 0;
	/// @brief
	/// Returns the name of the event
	virtual const char* GetName() const override = 0;

	map<int, vector<Direction>> getDirectionMap() { return directionMap; };
protected:
	int objectOneId;
	int objectTwoId;
	map<int, vector<Direction>> directionMap;
};

/// @brief
/// OnCollisionEvent is fired when a a collision ended
class OnCollisionEndEvent : public OnCollisionEvent {
public:
	OnCollisionEndEvent(int _objectOneId, int _objectTwoId, const map<int, vector<Direction>> _directionMap)
		: OnCollisionEvent(_objectOneId, _objectTwoId, _directionMap) {};

	virtual const char* GetName() const override { return "Collision end Event"; }
	EventType GetEventType() const override { return EventType::CollisionEnd; }
};

/// @brief
/// OnCollisionEvent is fired when a a collision started
class OnCollisionBeginEvent : public OnCollisionEvent {
public:
	OnCollisionBeginEvent(int _objectOneId, int _objectTwoId, const map<int, vector<Direction>> _directionMap)
		: OnCollisionEvent(_objectOneId, _objectTwoId, _directionMap) {};

	virtual const char* GetName() const override { return "Collision begin Event"; }
	virtual EventType GetEventType() const override { return EventType::CollisionBegin; }
};