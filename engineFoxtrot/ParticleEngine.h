#pragma once
#include "ParticleFacade.h"

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

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




