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
	for (Object * object : (*pointerToCurrentScene)->getAllObjectsInScene()) {
		if (object != nullptr && object->getIsParticle()) {
			((ParticleAdapter*)object)->update();

			checkIfObjectValueAndParticleValueMatch((ParticleAdapter&)object);
		}
	}
}

void ParticleEngine::checkIfObjectValueAndParticleValueMatch(ParticleAdapter& particle)
{
	if (particle.getPositionX() != particle.getPositionX())
	{
		particle.setPositionX(particle.getPositionX());
	}

	if (particle.getPositionY() != particle.getPositionY())
	{
		particle.setPositionY(particle.getPositionY());
	}
}


