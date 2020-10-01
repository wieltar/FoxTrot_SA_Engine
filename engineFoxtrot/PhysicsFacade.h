#pragma once

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"
#include "IPhysicsFacade.h"
#include <vector>;
#include "box2d/box2d.h"
#include "Object.h"
#include "ObjectData.h"

class PhysicsFacade : public IPhysicsFacade
{
public:
	PhysicsFacade();
	~PhysicsFacade();
	std::vector<Object> temp = std::vector<Object>();

	void addGround();
	void registerRectangle(Object object);

	b2Body* findBody(int objectId);
	Object getObject(int objectId);

	void MoveLeft(int objectId);
	void MoveRight(int objectId);
	void Jump(int objectId);
	void JumpLeft(int objectId);
	void JumpRight(int objectId);

//private:
	b2World world = b2World(b2Vec2(0.0f, 80.0f));
};




