#pragma once
#include "IParticleFacade.h"

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

#if(EXPORT)
class DLLEXPORT ParticleFacade : public IParticleFacade
#else
class ParticleFacade : public IParticleFacade
#endif
{
public:
	ParticleFacade();
	~ParticleFacade();

private:

};




