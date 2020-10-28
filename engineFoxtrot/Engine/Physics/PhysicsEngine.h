#pragma once
// TODO wrong way to include event, identify why it breaks
#include "Events/Event.h"
#include "Events/Action/ActionEvent.h"
#include "PhysicsFacade.h"
#include "../SceneManager/Scene.h"


#if(EXPORT)
class DLLEXPORT PhysicsEngine : public EventListener
#else
class PhysicsEngine
#endif
{
public:
	PhysicsEngine();
	~PhysicsEngine();

	void registerObjectInCurrentVectorWithPhysicsEngine();

	void handleAction(Event& event);
	void update30(Event& tick30Event);

	//Set to private after testing!!!
	IPhysicsFacade * physicsFacade = new PhysicsFacade();
	Scene** pointerToCurrentScene = nullptr;

private:

	// CurrentScene is stored because if this changes then the objects need to be reset.
	int currentSceneID = 0;
	Object* getObject(const int objectId);
};
