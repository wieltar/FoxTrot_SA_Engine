#pragma once

#include "PhysicsBody.h"

/// @brief 
/// Interface facade for all physics actions
#if(EXPORT)
class DLLEXPORT IPhysicsFacade
#else
class IPhysicsFacade
#endif
{
public:
	IPhysicsFacade() {};
	virtual ~IPhysicsFacade() {};

	virtual void addStaticObject(PhysicsBody* object) = 0;
	virtual void addDynamicObject(PhysicsBody* object) = 0;

	virtual PhysicsBody* getPhysicsObject(const int objectId) = 0;

	virtual void MoveLeft(const int objectId) = 0;
	virtual void MoveRight(const int objectId) = 0;
	virtual void Jump(const int objectId) = 0;

	virtual void update() = 0;

	virtual void cleanMap() = 0;
private:

};




