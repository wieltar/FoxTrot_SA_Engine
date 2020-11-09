#pragma once
// TODO wrong way to include event, identify why it breaks
#include "Events/Event.h"
#include "Events/Action/ActionEvent.h"
#include "IPhysicsFacade.h"

#include "../SceneManager/Scene.h"

class API PhysicsEngine
{
public:
	PhysicsEngine();
	~PhysicsEngine();

	void registerObjectInCurrentVectorWithPhysicsEngine();

	void handleAction(Event& event);
	void update30(Event& tick30Event);

	//Set to private after testing!!!
	IPhysicsFacade* physicsFacade;
	Scene** pointerToCurrentScene = nullptr;

private:

	// CurrentScene is stored because if this changes then the objects need to be reset.
	int currentSceneID = 0;
	Object* getObject(const int objectId);
};
