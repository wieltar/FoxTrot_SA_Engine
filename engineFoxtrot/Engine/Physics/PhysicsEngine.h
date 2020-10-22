#pragma once
// TODO wrong way to include event, identify why it breaks
#include "Events/Event.h"
#include "PhysicsFacade.h"

#if(EXPORT)
class DLLEXPORT PhysicsEngine : public EventListener
#else
class PhysicsEngine
#endif
{
public:
	vector <Object*>* pointerToObjectVector = nullptr;

	PhysicsEngine();
	~PhysicsEngine();

	void registerObjectInCurrentVectorWithPhysicsEngine();

	void MoveLeft(const int objectId);
	void MoveRight(const int objectId);
	void Jump(const int objectId);
	void JumpLeft(const int objectId);
	void JumpRight(const int objectId);

	void update30(Event& tick30Event);

	//Set to private after testing!!!
	IPhysicsFacade * physicsFacade = new PhysicsFacade;
private:

	Object* getObject(const int objectId);
};
