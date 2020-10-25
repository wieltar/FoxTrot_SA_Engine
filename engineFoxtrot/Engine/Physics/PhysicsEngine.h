#pragma once
// TODO wrong way to include event, identify why it breaks
#include "Events/Event.h"
#include "Events/Action/ActionEvent.h"
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

	void handleAction(Event& event);
	void update30(Event& tick30Event);

	//Set to private after testing!!!
	IPhysicsFacade * physicsFacade = new PhysicsFacade;
private:

	Object* getObject(const int objectId);
};
