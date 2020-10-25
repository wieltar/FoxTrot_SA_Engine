#pragma once
#include "IParticleFacade.h"


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




