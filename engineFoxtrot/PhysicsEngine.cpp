
#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine()
{
}

PhysicsEngine::~PhysicsEngine()
{
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
	for (Object* obj : *pointerToObjectVector)
	{
		PhysicsBody * phyObj = new PhysicsBody;
		phyObj->angle = obj->getAngle();
		phyObj->density = obj->getDensity();
		phyObj->friction = obj->getFriction();
		phyObj->height = obj->getHeight();
		phyObj->width = obj->getWidth();
		phyObj->posX = obj->getPositionX();
		phyObj->posY = obj->getPositionY();
		phyObj->jumpHeight = obj->getJumpHeight();
		phyObj->objectID = obj->getId();
		phyObj->restitution = obj->getRestitution();
		phyObj->speed = obj->getSpeed();
		cout << "Registering object : " << phyObj->objectID << endl;

		if (obj->getStatic())
		{
			physicsFacade->addGround(phyObj);
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

void PhysicsEngine::MoveLeft(int objectId)
{

}

void PhysicsEngine::MoveRight(int objectId)
{

}

void PhysicsEngine::Jump(int objectId)
{

}

void PhysicsEngine::JumpLeft(int objectId)
{

}

void PhysicsEngine::JumpRight(int objectId)
{

}


