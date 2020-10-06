#include "PhysicsBody.h"

int PhysicsBody::getId() const { return this->objectID; }


void PhysicsBody::setPositionX(float x) { this->posX = x; this->object->setPositionX(x); }
float PhysicsBody::getPositionX() const { return posX; }

void PhysicsBody::setPositionY(float y) { this->posY = y; this->object->setPositionY(y); }
float PhysicsBody::getPositionY() const { return posY; }

void PhysicsBody::setRotation(float r) { this->rotation = r; this->object->setRotation(r); }
float PhysicsBody::getRotation() const { return rotation; }

void PhysicsBody::setHeight(float h) { this->height = h; this->object->setHeight(h);}
float PhysicsBody::getHeight() const { return height; }

void PhysicsBody::setWidth(float w) { this->width = w; this->object->setWidth(w);}
float PhysicsBody::getWidth() const { return width; }

void PhysicsBody::setRestitution(float r) { this->restitution = r; this->object->setRestitution(r); }
float PhysicsBody::getRestitution() const { return this->restitution;}

void PhysicsBody::setFriction(float f) { this->friction = f;  this->object->setFriction(f);}
float PhysicsBody::getFriction() const { return this->friction; }

void PhysicsBody::setDensity(float d) { this->density = d;  this->object->setFriction(d);}
float PhysicsBody::getDensity() const { return this->density; }

void PhysicsBody::setSpeed(float s) { this->speed = s; this->object->setSpeed(s);}
float PhysicsBody::getSpeed() const { return this->speed; }

void PhysicsBody::setJumpHeight(float j) { this->jumpHeight = j; this->object->setJumpHeight(j);}
float PhysicsBody::getJumpHeight() const { return this->jumpHeight; }