#pragma once
#include "ParticleFacade.h"

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

class ParticleEngine
{
public:
	ParticleEngine();
	~ParticleEngine();

	// Set to Private after testing!!!
	IParticleFacade* particleEngine = new ParticleFacade;
private:

};




