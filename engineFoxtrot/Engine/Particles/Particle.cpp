#include "stdafx.h"
#include "Particle.h"


/// @brief Constructor
Particle::Particle()
{
}

/// @brief Destructor
Particle::~Particle()
{
}

void Particle::addParticle(int particleID, int width, int height, float xPosition, float yPosition, float xVelocity, float yVelocity)
{
	ParticleStruct particle;
	particle.particleID = particleID;
	particle.width = width;
	particle.height = height;
	particle.xPosition = xPosition;
	particle.yPosition = yPosition;
	particle.xVelocity = xVelocity;
	particle.yVelocity = yVelocity;
	particleList.push_back(particle);
}

void Particle::particleMove()
{
	for (ParticleStruct particle : particleList) {
		particle.xPosition += particle.xVelocity;
		particle.yPosition += particle.yVelocity;
	}
}
