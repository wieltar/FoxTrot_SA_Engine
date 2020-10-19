#pragma once
#include "ParticleStruct.h"


#if(EXPORT)
class DLLEXPORT Particle
#else
class Particle
#endif
{
public:
	Particle();
	~Particle();

	void addParticle(int particleID, int width, int height, float xPosition, float yPosition, float xVelocity, float yVelocity);
	void particleMove();

	vector<ParticleStruct> particleList;

	void createJumpParticle(float _xPosition, float _yPostion);
	
private:

};




