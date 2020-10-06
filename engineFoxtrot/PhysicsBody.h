#pragma once

#include "box2d/box2d.h"
#include "Object.h"

class PhysicsBody
{
public:
	PhysicsBody(Object* object) :
		objectID(object->getId()),
		height(object->getHeight()),
		width(object->getWidth()),
		posX(object->getPositionX()),
		posY(object->getPositionY()),
		speed(object->getSpeed()),
		friction(object->getFriction()),
		restitution(object->getRestitution()),
		density(object->getDensity()),
		rotation(object->getRotation()),
		jumpHeight(object->getJumpHeight()) {
			this->object = *object;
		};	
	~PhysicsBody() {
	}
	int getId() const;

	void setPositionX(float);
	float getPositionX() const;

	void setPositionY(float);
	float getPositionY() const;

	//TODO same as angle??

	void setRotation(float);
	float getRotation() const;

	void setHeight(float);
	float getHeight() const;

	void setWidth(float);
	float getWidth() const;

	void setRestitution(float val);
	float getRestitution() const;

	void setFriction(float val);
	float getFriction() const;

	void setDensity(float val);
	float getDensity() const;

	void setSpeed(float val);
	float getSpeed() const;

	void setJumpHeight(float val);
	float getJumpHeight() const;
private:
	int objectID = 0;
	float height = 0;
	float width = 0;
	float posX = 0;
	float posY = 0;
	float speed = 0;
	float friction = 0;
	float restitution = 0;
	float density = 0;
	float rotation = 0;
	float jumpHeight = 0;
	Object object;
};