
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
			physicsFacade->registerRectangle(phyObj);
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
void PhysicsEngine::MoveLeft(int objectId) {
	this->physicsFacade->MoveLeft(objectId);
}

/// @brief 
/// @param objectId 
void PhysicsEngine::MoveRight(int objectId) {
	this->physicsFacade->MoveRight(objectId);
}

/// @brief 
/// @param objectId 
void PhysicsEngine::Jump(int objectId) {
	this->physicsFacade->Jump(objectId);
}

/// @brief 
/// @param objectId 
void PhysicsEngine::JumpLeft(int objectId) {
	this->physicsFacade->JumpLeft(objectId);
}

/// @brief 
/// @param objectId 
void PhysicsEngine::JumpRight(int objectId) {
	this->physicsFacade->JumpRight(objectId);
}


