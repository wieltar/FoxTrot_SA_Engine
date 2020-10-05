#pragma once

#include "PhysicsBody.h"

#if(EXPORT)
class DLLEXPORT IPhysicsFacade
#else
class IPhysicsFacade
#endif
{
public:
	IPhysicsFacade() {};
	virtual ~IPhysicsFacade() {};

	virtual void addGround(PhysicsBody* ground) = 0;
	virtual void registerRectangle(PhysicsBody* object) = 0;

	virtual PhysicsBody* getPhysicsObject(int objectId) = 0;

	virtual void MoveLeft(int objectId) = 0;
	virtual void MoveRight(int objectId) = 0;
	virtual void Jump(int objectId) = 0;
	virtual void JumpLeft(int objectId) = 0;
	virtual void JumpRight(int objectId) = 0;

	virtual void update() = 0;
private:

};




