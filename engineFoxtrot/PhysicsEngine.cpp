#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine()
{
}

PhysicsEngine::~PhysicsEngine()
{
	delete physicsFacade;
}

void PhysicsEngine::addStaticObject(Object& ground) {
	this->physicsFacade->addStaticObject(ground);
}

void PhysicsEngine::registerRectangle(Object& object) {
	this->physicsFacade->registerRectangle(object);
}

Object* PhysicsEngine::getObject(int objectId) {
	return this->physicsFacade->getObject(objectId);
}

void PhysicsEngine::MoveLeft(int objectId) {
	this->physicsFacade->MoveLeft(objectId);
}

void PhysicsEngine::MoveRight(int objectId) {
	this->physicsFacade->MoveRight(objectId);
}

void PhysicsEngine::Jump(int objectId) {
	this->physicsFacade->Jump(objectId);
}

void PhysicsEngine::JumpLeft(int objectId) {
	this->physicsFacade->JumpLeft(objectId);
}

void PhysicsEngine::JumpRight(int objectId) {
	this->physicsFacade->JumpRight(objectId);
}

void PhysicsEngine::update() {
	this->physicsFacade->update();
}