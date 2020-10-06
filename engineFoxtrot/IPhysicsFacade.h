#pragma once

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"
#include <vector>
#include <map>
#include "box2d/box2d.h"
#include "Object.h"

#if(EXPORT)
class DLLEXPORT IPhysicsFacade
#else
class IPhysicsFacade
#endif
{
public:
	IPhysicsFacade() {};
	virtual ~IPhysicsFacade() {};
	//TODO load from engine objects
	std::vector<Object*> temp = std::vector<Object*>();

	virtual void addStaticObject(Object& ground) = 0;
	virtual void registerRectangle(Object& object) = 0;

	virtual Object* getObject(int objectId) = 0;

	virtual void MoveLeft(int objectId) = 0;
	virtual void MoveRight(int objectId) = 0;
	virtual void Jump(int objectId) = 0;
	virtual void JumpLeft(int objectId) = 0;
	virtual void JumpRight(int objectId) = 0;

	virtual void update() = 0;
private:

};




