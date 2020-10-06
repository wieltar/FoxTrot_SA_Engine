
#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine()
{
}

PhysicsEngine::~PhysicsEngine()
{
	delete physicsFacade;
}

Object* PhysicsEngine::getObject(int objectId)
{
	for (Object * obj : *pointerToObjectVector)
	{
		if (obj->getId() == objectId) 
		{
			return obj;
		}
	}
	throw PHYSICS_ENGINE_OBJECT_DOESNT_EXIST;
}

void PhysicsEngine::registerObjectInCurrentVectorWithPhysicsEngine()
{
	cout << "Size pointertoObj: " << pointerToObjectVector->size() << endl;
	for (Object* object : *pointerToObjectVector)
	{
		PhysicsBody * phyObj = new PhysicsBody(object);
		cout << "Registering object : " << phyObj->getId() << endl;

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

void PhysicsEngine::update30()
{
	physicsFacade->update();

}
void PhysicsEngine::MoveLeft(int objectId) {
	this->physicsFacade->MoveLeft(objectId);
}

void PhysicsEngine::MoveRight(int objectId) {
	this->physicsFacade->MoveRight(objectId);
}

void PhysicsEngine::Jump(int objectId) {
	this->physicsFacade->Jump(objectId);
}

void PhysicsEngine::JumpLeft(int objectId) {
	this->physicsFacade->JumpLeft(objectId);
}

void PhysicsEngine::JumpRight(int objectId) {
	this->physicsFacade->JumpRight(objectId);
}


