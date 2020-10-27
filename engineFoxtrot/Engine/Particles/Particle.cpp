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
	particle.particleSpriteID = particleID;
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

void Particle::createJumpParticle(float _xPosition, float _yPostion)
{
	for (int i = 0; i < 10; i++) {
		ParticleStruct particle;

		particle.particleSpriteID = 1;
		particle.height = 10;
		particle.width = 10;
		particle.xVelocity = (rand() % 100) / 5 / 10;
		particle.yPosition = (rand() % 100) / 5 / 10;
		particle.xPosition = _xPosition;
		particle.yPosition = _yPostion;

		particleList.push_back(particle);
	}
}

vector<ParticleStruct> Particle::getParticleList() const
{
	return particleList;
}
