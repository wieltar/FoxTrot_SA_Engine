#pragma once
#include "../SceneManager/Scene.h"




#if(EXPORT)
class DLLEXPORT ParticleEngine
#else
class ParticleEngine
#endif
{
public:
	ParticleEngine();
	~ParticleEngine();


	void onUpdate();


	Scene** pointerToCurrentScene = nullptr;

private:


};




