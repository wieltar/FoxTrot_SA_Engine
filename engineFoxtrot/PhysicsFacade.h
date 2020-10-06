#pragma once
#include "IPhysicsFacade.h"

#define VELOCITY_ITERATIONS 8
#define POSITION_ITERATIONS 3

#define TIMESTEP_SEC 1.0f
#define TIMESTEP_FRAMES 60.0f

#define JUMP_SPEED 10

#define GRAVITY_FALL 80.0f // So when I said gravity is (0,80) that means gravity is applied at a rate of 80 pixels along the y axis per second. 
#define GRAVITY_SCALE 0.0f

#define X_AXIS_STATIC 0
#define Y_AXIS_STATIC 0

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

	void addStaticObject(Object& ground) override;
	void registerRectangle(Object& object) override;
	
	Object* getObject(int objectId) override;

	void MoveLeft(int objectId) override;
	void MoveRight(int objectId) override;
	void Jump(int objectId) override;
	void JumpLeft(int objectId) override;
	void JumpRight(int objectId) override;

	void update() override;

private:
	const int INCREASE_JUMP_SPEED = JUMP_SPEED;
	b2World world = b2World(b2Vec2(GRAVITY_SCALE, GRAVITY_FALL));
	float timeStep = TIMESTEP_SEC / TIMESTEP_FRAMES;

	int32 velocityIterations = VELOCITY_ITERATIONS;
	int32 positionIterations = POSITION_ITERATIONS;
		
	b2Body* findBody(int objectId);
};




