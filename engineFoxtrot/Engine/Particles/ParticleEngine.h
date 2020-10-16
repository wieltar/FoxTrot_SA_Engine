#pragma once
#include "Particle.h"


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
	void createParticle(int amountOfParticles, float xPosition, float yPostion);

	vector<Particle*> getParticlesVector() { return particles; };
private:
	vector<Particle*> particles;

};




