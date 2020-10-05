#pragma once

#include "box2d/box2d.h"

struct PhysicsBody
{
	int objectID = 0;
	float height = 0;
	float width = 0;
	float posX = 0;
	float posY = 0;
	float speed = 0;
	float friction = 0;
	float restitution = 0;
	float density = 0;
	float angle = 0;
	float jumpHeight = 0;
	b2Body* body;
};