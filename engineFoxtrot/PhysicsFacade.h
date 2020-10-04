#pragma once

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"
#include "IPhysicsFacade.h"
#include <vector>
#include <map>
#include "box2d/box2d.h"
#include "Object.h"

#if(EXPORT)
class DLLEXPORT PhysicsFacade : public IPhysicsFacade
#else
class PhysicsFacade : public IPhysicsFacade
#endif
{
public:

	PhysicsFacade();
	~PhysicsFacade();
	//TODO load from engine objects
	std::vector<Object*> temp = std::vector<Object*>();
	std::map<int, b2Body*> bodies = std::map<int, b2Body*>();

	void addGround(Object& g);
	void registerRectangle(Object& object);

	b2Body* findBody(int objectId);
	Object* getObject(int objectId);

	void MoveLeft(int objectId);
	void MoveRight(int objectId);
	void Jump(int objectId);
	void JumpLeft(int objectId);
	void JumpRight(int objectId);

	void update();

private:
	b2World world = b2World(b2Vec2(0.0f, 80.0f));
	float timeStep = 1.0f / 60.0f;

	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	
	b2Body* currentBody = nullptr;
	Object* currentObject = nullptr;
};




