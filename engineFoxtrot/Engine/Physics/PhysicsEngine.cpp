#include "stdafx.h"
#include <Events\AppTickEvent30.h>
#include "Events/EventSingleton.h"
#include "PhysicsEngine.h"

/// @brief Constructor
PhysicsEngine::PhysicsEngine()
{
	EventSingleton::get_instance().setEventCallback<AppTickEvent30>(BIND_EVENT_FN(PhysicsEngine::update30));
	EventSingleton::get_instance().setEventCallback<ActionEvent>(BIND_EVENT_FN(PhysicsEngine::handleAction));
}

void PhysicsEngine::handleAction(Event& event) {
	auto actionEvent = static_cast<ActionEvent&>(event);

	auto direction = actionEvent.GetDirection();
	auto objectId = actionEvent.GetObjectId();
	switch (direction)
	{
		case Direction::UP:
			this->physicsFacade->Jump(objectId);
		break;
		case Direction::LEFT:
			this->physicsFacade->MoveLeft(objectId);
			break;
		case Direction::RIGHT:
			this->physicsFacade->MoveRight(objectId);
			break;
		default:
			break;
	}
}

/// @brief Destructor
PhysicsEngine::~PhysicsEngine()
{
	delete physicsFacade;
}

/// @brief 
/// A function to search a object with the ObjectId
/// If a object is not found throw PHYSICS_ENGINE_OBJECT_DOESNT_EXIST
/// @param objectId 
/// Identifier for ObjectID
Object* PhysicsEngine::getObject(const int objectId)
{
	for (Object * obj : *pointerToObjectVector)
	{
		if (obj->getSpriteID() == objectId)
		{
			return obj;
		}
	}
	throw PHYSICS_ENGINE_OBJECT_DOESNT_EXIST;
}

/// @brief 
/// A function to create all objects in the facade
void PhysicsEngine::registerObjectInCurrentVectorWithPhysicsEngine()
{
	cout << "Size pointertoObj: " << pointerToObjectVector->size() << endl;
	for (Object* object : *pointerToObjectVector)
	{
		PhysicsBody * phyObj = new PhysicsBody(object);
		cout << "Registering object : " << phyObj->getSpriteID() << endl;

		if (object->getStatic())
		{
			physicsFacade->addStaticObject(phyObj);
		}
		else
		{
			physicsFacade->addNonStaticObject(phyObj);
		}
	}
}

/// @brief 
/// Handle the tick given from the thread. 
void PhysicsEngine::update30(Event& tick30Event)
{
	//tick30Event = (AppTickEvent30&)tick30Event;
	physicsFacade->update();
}


