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

	void MoveLeft(int const objectId);
	void MoveRight(int const objectId);
	void Jump(int const objectId);
	void JumpLeft(int const objectId);
	void JumpRight(int const objectId);

	void update30();

	void update(Object* object) override {
		std::cout << "Handle notification " << std::endl;
	}

	//Set to private after testing!!!
	IPhysicsFacade * physicsFacade = new PhysicsFacade;
private:

	Object* getObject(int objectId);
};





