
#include "PhysicsEngine.h"

/// @brief Constructor
PhysicsEngine::PhysicsEngine()
{
}

/// @brief Destructor
PhysicsEngine::~PhysicsEngine()
{
	delete physicsFacade;
}

/// @brief 
/// @param objectId 
/// A function to search a object with the ObjectId
/// If a object is not found throw PHYSICS_ENGINE_OBJECT_DOESNT_EXIST
Object* PhysicsEngine::getObject(int objectId)
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
void PhysicsEngine::update30()
{
	physicsFacade->update();

}
/// @brief 
/// @param objectId 
/// A function to add a linearImpulse to a object for moving to left
void PhysicsEngine::MoveLeft(int objectId) {
	this->physicsFacade->MoveLeft(objectId);
}

/// @brief 
/// @param objectId 
/// A function to add a linearImpulse to a object for moving to right 
void PhysicsEngine::MoveRight(int objectId) {
	this->physicsFacade->MoveRight(objectId);
}

/// @brief 
/// @param objectId 
/// A function to add a linearImpulse to a object for jumping
void PhysicsEngine::Jump(int objectId) {
	this->physicsFacade->Jump(objectId);
}

/// @brief 
/// @param objectId 
/// A function to add a linearImpulse to a object for jumping to the left
void PhysicsEngine::JumpLeft(int objectId) {
	this->physicsFacade->JumpLeft(objectId);
}

/// @brief 
/// @param objectId 
/// A function to add a linearImpulse to a object for jumping to the right
void PhysicsEngine::JumpRight(int objectId) {
	this->physicsFacade->JumpRight(objectId);
}


