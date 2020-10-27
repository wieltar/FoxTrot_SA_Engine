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

	void addParticle(int particleSpirteID, int width, int height, float xPosition, float yPosition, float xVelocity, float yVelocity);
	void particleMove();


	void createJumpParticle(float _xPosition, float _yPostion);
	vector<ParticleStruct> getParticleList() const;
	
private:
	vector<ParticleStruct> particleList;

};




