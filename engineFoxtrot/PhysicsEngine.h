#pragma once

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"
#include "PhysicsFacade.h"
#include "EventManager.h"

#if(EXPORT)
class DLLEXPORT PhysicsEngine : public EventListener
#else
class PhysicsEngine : public EventListener
#endif
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
private:
};





