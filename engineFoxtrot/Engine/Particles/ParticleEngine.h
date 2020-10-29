#pragma once
#include "../SceneManager/Scene.h"
#include "Events/Event.h"
#include "Events/Action/ActionEvent.h"

#if(EXPORT)
class DLLEXPORT ParticleEngine
#else
class ParticleEngine
#endif
{
public:
	ParticleEngine();
	~ParticleEngine();


	void onUpdate(Event& tickEvent);


	Scene** pointerToCurrentScene = nullptr;

private:


};




