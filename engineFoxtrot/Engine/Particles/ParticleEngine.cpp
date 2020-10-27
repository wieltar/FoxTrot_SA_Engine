#include "stdafx.h"
#include "ParticleEngine.h"

/// @brief Constructor
ParticleEngine::ParticleEngine()
{
}

/// @brief Destructor
ParticleEngine::~ParticleEngine()
{
}

void ParticleEngine::onUpdate()
{

}

void ParticleEngine::createCustomParticle(int particleSpirteID, int amountOfParticles, float xPosition, float yPostion)
{
}

void ParticleEngine::createJumpParticle(int particleSpirteID, float xPosition, float yPosition)
{
	Particle *particle = new Particle();

	particle->createJumpParticle(xPosition, yPosition);
	
	particles.push_back(particle);

	delete particle;
}
