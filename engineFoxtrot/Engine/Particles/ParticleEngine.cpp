#include "stdafx.h"
#include "ParticleEngine.h"
#include <Events\AppTickEvent60.h>
#include <Events\EventSingleton.h>

/// @brief Constructor
ParticleEngine::ParticleEngine()
{
	EventSingleton::get_instance().setEventCallback<AppTickEvent60>(BIND_EVENT_FN(ParticleEngine::onUpdate));
}

/// @brief Destructor
ParticleEngine::~ParticleEngine()
{
}

void ParticleEngine::onUpdate(Event& tickEvent)
{
	if ((*pointerToCurrentScene)->getAllParticlesInScene().size() == 0) return;
	for (Particle * particle : (*pointerToCurrentScene)->getAllParticlesInScene()) {
		if (particle != nullptr) {
			particle->update();
		}
	}
}


