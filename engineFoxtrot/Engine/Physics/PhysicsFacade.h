#pragma once
#include "IPhysicsFacade.h"
#include "PhysicsBody.h"
#include "Events/EventSingleton.h"
#include "Events/Action/OnCollisionEvent.h"

#define PI 3.14159f
#define TOTAL_DEGREES 180.0f

#define VELOCITY_ITERATIONS 8
#define POSITION_ITERATIONS 3

#define TIMESTEP_SEC 1.0f
#define TIMESTEP_FRAMES 60.0f

#define INCREASE_JUMP_SPEED 10
#define GRAVITY_FALL 80.0f // So when I said gravity is (0,80) that means gravity is applied at a rate of 80 pixels along the y axis per second.
#define GRAVITY_SCALE 0.0f

#define X_AXIS_STATIC 0
#define Y_AXIS_STATIC 0

struct CollisionStruct {
	PhysicsBody* object1 = nullptr;
	PhysicsBody* object2 = nullptr;
};

class b2Fixture;
class b2World;
class b2Body;

/// @brief 
/// PhysicsFacade class. Class for update physics off objects
class PhysicsFacade : public IPhysicsFacade
{
public:
	PhysicsFacade();
	~PhysicsFacade();

	void addStaticObject(PhysicsBody* object) override;
	void addDynamicObject(PhysicsBody* object) override;

	PhysicsBody* getPhysicsObject(const int objectId) override;

	void MoveLeft(const int objectId) override;
	void MoveRight(const int objectId) override;
	void Jump(const int objectId) override;

	CollisionStruct getObjectsByFixture(b2Fixture* fixture1, b2Fixture* fixture2);
	void update() override;
	void cleanMap();

private:
	b2World * world;
	const float timeStep = TIMESTEP_SEC / TIMESTEP_FRAMES;

	map <PhysicsBody*, b2Body*> bodies;
	b2Body* findBody(const int objectId);
};
