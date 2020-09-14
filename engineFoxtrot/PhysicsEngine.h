#pragma once

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"
#include "PhysicsFacade.h"

class PhysicsEngine
{
public:
	PhysicsEngine();
	~PhysicsEngine();

	//Set to private after testing!!!
	IPhysicsFacade * physicsEngine = new PhysicsFacade;
private:

};





