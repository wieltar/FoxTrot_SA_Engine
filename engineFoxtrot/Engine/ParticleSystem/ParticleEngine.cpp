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

/// @brief OnUpdate for updating particles
/// @param tickEvent tick event listening to
void ParticleEngine::onUpdate(Event& tickEvent)
{
	if ((*pointerToCurrentScene)->getAllObjectsInScene().size() == 0) return;
	for (Object * particle : (*pointerToCurrentScene)->getAllObjectsInScene()) {
		if (particle != nullptr && particle->getIsParticle()) {
			((ParticleAdapter*)particle)->update();
		}
	}
}


