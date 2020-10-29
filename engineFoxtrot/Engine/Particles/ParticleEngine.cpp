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
	for (Particle * particle : (*pointerToCurrentScene)->getAllParticlesInScene()) {
		if (particle != nullptr) {
			particle->update();
		}
	}
}


