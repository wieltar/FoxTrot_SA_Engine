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
	vector <Object*>* pointerToObjectVector = nullptr;

	PhysicsEngine();
	~PhysicsEngine();

	void registerObjectInCurrentVectorWithPhysicsEngine();

	void MoveLeft(const int objectId);
	void MoveRight(const int objectId);
	void Jump(const int objectId);
	void JumpLeft(const int objectId);
	void JumpRight(const int objectId);

	void update30();

	void update(Object* object) override {
		std::cout << "Handle notification " << std::endl;
	}

	//Set to private after testing!!!
	IPhysicsFacade * physicsFacade = new PhysicsFacade;
private:

	Object* getObject(const int objectId);
};





