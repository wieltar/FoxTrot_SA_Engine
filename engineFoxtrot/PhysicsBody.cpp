#include "PhysicsBody.h"

PhysicsBody::PhysicsBody(Object* object) : objectID(object->getSpriteID()), height(object->getHeight()), width(object->getWidth()), posX(object->getPositionX()),
	posY(object->getPositionY()), speed(object->getSpeed()), friction(object->getFriction()), restitution(object->getRestitution()), density(object->getDensity()),
	rotation(object->getRotation()), jumpHeight(object->getJumpHeight()) {
	this->object = object;
};
PhysicsBody::~PhysicsBody() {
}

int PhysicsBody::getSpriteID() const { return this->objectID; }

void PhysicsBody::setPositionX(const float x) { this->posX = x; this->object->setPositionX(x); }
float PhysicsBody::getPositionX() const { return posX; }

void PhysicsBody::setPositionY(const float y) { this->posY = y; this->object->setPositionY(y); }
float PhysicsBody::getPositionY() const { return posY; }

void PhysicsBody::setRotation(const float r) { this->rotation = r; this->object->setRotation(r); }
float PhysicsBody::getRotation() const { return rotation; }

void PhysicsBody::setHeight(const float h) { this->height = h; this->object->setHeight(h);}
float PhysicsBody::getHeight() const { return height; }

void PhysicsBody::setWidth(const float w) { this->width = w; this->object->setWidth(w);}
float PhysicsBody::getWidth() const { return width; }

void PhysicsBody::setRestitution(const float r) { this->restitution = r; this->object->setRestitution(r); }
float PhysicsBody::getRestitution() const { return this->restitution;}

void PhysicsBody::setFriction(const float f) { this->friction = f;  this->object->setFriction(f);}
float PhysicsBody::getFriction() const { return this->friction; }

void PhysicsBody::setDensity(const float d) { this->density = d;  this->object->setFriction(d);}
float PhysicsBody::getDensity() const { return this->density; }

void PhysicsBody::setSpeed(const float s) { this->speed = s; this->object->setSpeed(s);}
float PhysicsBody::getSpeed() const { return this->speed; }

void PhysicsBody::setJumpHeight(const float j) { this->jumpHeight = j; this->object->setJumpHeight(j);}
float PhysicsBody::getJumpHeight() const { return this->jumpHeight; }