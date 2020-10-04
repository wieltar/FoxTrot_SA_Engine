#pragma once

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"
#include "PhysicsFacade.h"
#include "EventManager.h"

class PhysicsEngine : public EventListener
{
public:
	EventManager* eventManager{ new EventManager };
	PhysicsEngine();
	~PhysicsEngine();

	//Set to private after testing!!!
	IPhysicsFacade * physicsEngine = new PhysicsFacade;

	void update(Object* object) override {
		std::cout << "Handle notification " << std::endl;
	}


	void MoveLeft(int objectId);
	void MoveRight(int objectId);
	void Jump(int objectId);
	void JumpLeft(int objectId);
	void JumpRight(int objectId);


private:
};





