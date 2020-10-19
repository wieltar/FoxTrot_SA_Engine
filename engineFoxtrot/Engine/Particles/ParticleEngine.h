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
	void createCustomParticle(int amountOfParticles, float xPosition, float yPostion);
	void createJumpParticle(float xPosition, float yPosition);

	vector<Particle*> getParticlesVector() { return particles; };

private:
	vector<Particle*> particles;

};




