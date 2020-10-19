#include "stdafx.h"
#include "SDL.h"
#include "ParticleTest.h"

ParticleTest::ParticleTest()
{
}

ParticleTest::ParticleTest(float _x, float _y, float xVel, float yVel, int life, int _color)
{
	x = _x;
	y = _y;
	xvel = xVel;
	yvel = yVel;
	endTime = SDL_GetTicks() + life;
	color = _color;
		
}

ParticleTest::~ParticleTest()
{
}

void ParticleTest::move()
{
	x += xvel;
	y += yvel;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > 600)
		x = 599;
	if (y > 480)
		y = 479;

}

void ParticleTest::show()
{
}

void ParticleTest::isDead()
{
}
