#pragma once
#include "IPhysicsFacade.h"

#define INCREASE_JUMP_SPEED = 10;
#define NO_MOVE_Y_LEVEL = 0;
#define NO_MOVE_X_LEVEL = 0;


/// @brief 
/// PhysicsFacade class. Class for update physics off objects
#if(EXPORT)
class DLLEXPORT PhysicsFacade : public IPhysicsFacade
#else
class PhysicsFacade : public IPhysicsFacade
#endif
{
public:
	PhysicsFacade();
	~PhysicsFacade();

	std::map<int, b2Body*> bodies = std::map<int, b2Body*>();

	void addGround(Object& ground) override;
	void registerRectangle(Object& object) override;
	
	Object* getObject(int objectId) override;

	void MoveLeft(int objectId) override;
	void MoveRight(int objectId) override;
	void Jump(int objectId) override;
	void JumpLeft(int objectId) override;
	void JumpRight(int objectId) override;

	void update() override;

private:
	const int INCREASE_JUMP_SPEED = 10;
	const int NO_MOVE_Y_LEVEL = 0;
	const int NO_MOVE_X_LEVEL = 0;
	b2World world = b2World(b2Vec2(0.0f, 80.0f));
	float timeStep = 1.0f / 60.0f;

	int32 velocityIterations = 6;
	int32 positionIterations = 2;
		
	b2Body* findBody(int objectId);
};




