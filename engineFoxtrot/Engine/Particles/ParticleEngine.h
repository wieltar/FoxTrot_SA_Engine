#pragma once
#include "ParticleFacade.h"
class ParticleEngine
{
public:
	ParticleEngine();
	~ParticleEngine();

	// Set to Private after testing!!!
	IParticleFacade* particleEngine = new ParticleFacade;
private:

};




