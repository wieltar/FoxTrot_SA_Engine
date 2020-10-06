#pragma once

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"
#include "PhysicsFacade.h"
#include "EventManager.h"

#if(EXPORT)
class DLLEXPORT PhysicsEngine : public EventListener
#else
class PhysicsEngine
#endif
{
public:
	EventManager* eventManager{ new EventManager };
	PhysicsEngine();
	~PhysicsEngine();




	void addStaticObject(Object& ground);
	void registerRectangle(Object& object);

	Object* getObject(int objectId);

	void MoveLeft(int objectId);
	void MoveRight(int objectId);
	void Jump(int objectId);
	void JumpLeft(int objectId);
	void JumpRight(int objectId);

	void update();

	// TODO set private when objects work according to plan
	IPhysicsFacade* physicsFacade = new PhysicsFacade;
private:
};





