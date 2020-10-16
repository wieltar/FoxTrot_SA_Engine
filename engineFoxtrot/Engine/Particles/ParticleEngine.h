#pragma once
#include "ParticleFacade.h"


#if(EXPORT)
class DLLEXPORT ParticleEngine
#else
class ParticleEngine
#endif
{
public:
	ParticleEngine();
	~ParticleEngine();

	// Set to Private after testing!!!
	IParticleFacade* particleEngine = new ParticleFacade;
private:

};




