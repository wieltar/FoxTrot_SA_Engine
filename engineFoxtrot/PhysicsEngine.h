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

	void registerObjectInCurrentVectorWithPhysicsEngine();

	vector <Object*>* pointerToObjectVector = nullptr;

	void MoveLeft(int objectId);
	void MoveRight(int objectId);
	void Jump(int objectId);
	void JumpLeft(int objectId);
	void JumpRight(int objectId);

	void update30();

	//Set to private after testing!!!
	IPhysicsFacade * physicsFacade = new PhysicsFacade;

	void update(Object* object) override {
		std::cout << "Handle notification " << std::endl;
	}

private:

	Object* getObject(int objectId);
};





