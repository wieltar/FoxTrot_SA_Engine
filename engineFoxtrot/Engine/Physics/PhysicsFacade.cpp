#include "stdafx.h"
#include "PhysicsFacade.h"
#include "./ContactListenerAdapter.h"

/// @brief Constructor
PhysicsFacade::PhysicsFacade()
{
	world.SetContactListener(new ContactListenerAdapter(this));
}

/// @brief Destructor
PhysicsFacade::~PhysicsFacade()
{
	// When a world leaves scope or is deleted by calling delete on a pointer, all the memory reserved for bodies, fixtures, and joints is freed.This is done to improve performanceand make your life easier.
	// However, you will need to nullify any body, fixture, or joint pointers you have because they will become invalid.
	// https://box2d.org/documentation/md__d_1__git_hub_box2d_docs_dynamics.html#autotoc_md113
}

CollisionStruct PhysicsFacade::getObjectsByFixture(b2Fixture* fixture1, b2Fixture* fixture2) {
	CollisionStruct collisionStruct = CollisionStruct();
	for (const auto& value : this->bodies) {
		auto fixtures = value.second->GetFixtureList();
		for (b2Fixture* f = value.second->GetFixtureList(); f; f = f->GetNext())
		{
			if (fixture1 == f)
				collisionStruct.object1 = value.first;
			else if (fixture2 == f)
				collisionStruct.object2 = value.first;

			if (collisionStruct.object1 != nullptr && collisionStruct.object2 != nullptr) break;
		}
	}
	return collisionStruct;
}

/// @brief 
/// A function to search a physicsObject with the ObjectId
/// If a body is not found throw PHYSICS_FACADE_OBJECT_DOESNT_EXIST
/// @param objectId 
/// Identifier for ObjectID
PhysicsBody* PhysicsFacade::getPhysicsObject(const int objectId)
{
	for (const auto& value : bodies) {
		if (value.first->getSpriteID() == objectId)
		{
			return value.first;
		}
	}
	throw PHYSICS_FACADE_OBJECT_DOESNT_EXIST;
}

/// @brief 
/// A (private) function for create a shape
/// The position is set to the bottom left
/// @param objectId 
/// Identifier for ObjectID
b2PolygonShape createShape(const PhysicsBody& object) {
	b2PolygonShape shape;
	float halfH = object.getHeight()/ 2; //Box2D needs the half height of a object
	float halfW = object.getWidth() / 2; //Box2D needs the half width of a object
	float posY = object.getPositionY() - object.getHeight() / 2; //Box2d needs the middle position
	float posX = object.getPositionX() + object.getWidth() / 2; //Box2d needs the middle position
	shape.SetAsBox(halfW, halfH, b2Vec2(posX, posY), object.getRotation());
	return shape;
}

/// @brief 
/// A function for register a non static object
/// @param Object 
/// The object to register
void PhysicsFacade::addStaticObject(PhysicsBody* object) {
	b2BodyDef groundBodyDef;
	groundBodyDef.type = b2_staticBody;
	b2Body* body = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox = createShape(*object);
	body->CreateFixture(&groundBox, 0.0f);
	b2FixtureDef fixtureDef;

	bodies.insert(pair<PhysicsBody*, b2Body*>(object, body));
}

/// @brief 
/// A function for register a non static object
/// @param Object 
/// The object to register
void PhysicsFacade::addDynamicObject(PhysicsBody* object)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	b2Body* body = world.CreateBody(&bodyDef);

	b2PolygonShape bodyBox = createShape(*object);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &bodyBox;
	fixtureDef.density = object->getDensity();
	fixtureDef.friction = object->getFriction();
	fixtureDef.restitution = object->getRestitution();

	body->CreateFixture(&fixtureDef);

	float posY = object->getPositionY() - object->getHeight() / 2; //Box2d needs the middle position
	float posX = object->getPositionX() + object->getWidth() / 2; //Box2d needs the middle position
	bodyDef.position.Set(posX, posY);
	bodyDef.linearVelocity = b2Vec2(0, object->getLinearVelocity());

	bodies.insert(pair<PhysicsBody*, b2Body*>(object, body));
}

/// @brief 
/// A function to search a body with the ObjectId
/// If a body is not found throw PHYSICS_FACADE_BODY_DOESNT_EXIST
/// @param objectId 
/// Identifier for ObjectID
b2Body* PhysicsFacade::findBody(const int objectId) {
	for (const auto& value : bodies) {
		if (value.first->getSpriteID() == objectId)
		{
			return value.second;
		}
	}
	throw PHYSICS_FACADE_BODY_DOESNT_EXIST;
}

//class member variable
int m_jumpTimeout = 0;
/// @brief 
/// A function to update the position information of all objects
/// The position is set to the bottom left
void PhysicsFacade::update() {
	this->world.Step(timeStep, VELOCITY_ITERATIONS, POSITION_ITERATIONS);

	for (auto const& it : bodies)
	{
		b2Body* body = it.second;

		if (body->GetType() == b2_staticBody) {
			continue;
		}
		PhysicsBody* object = it.first;
		object->setPositionX(body->GetWorldCenter().x - object->getWidth() / 2);
		object->setPositionY(body->GetWorldCenter().y + object->getHeight() / 2);

		if(object->getCanChangeAngle()) object->setRotation(body->GetAngle() * (TOTAL_DEGREES / PI));
		object->setLinearVelocity(body->GetLinearVelocity().y);
	}	
}

/// @brief 
/// A function to add a linearImpulse to a object for moving to left
/// @param objectId 
/// Identifier for ObjectID
void PhysicsFacade::MoveLeft(const int objectId)
{
	b2Body* body = findBody(objectId);
	const PhysicsBody* ob = getPhysicsObject(objectId);
	//body->ApplyLinearImpulse(b2Vec2(ob->getSpeed() * -1, Y_AXIS_STATIC), body->GetWorldCenter(), true);

	b2Vec2 vel = body->GetLinearVelocity();
	vel.y = ob->getLinearVelocity();
	vel.x = ob->getSpeed() *-1;
	body->SetLinearVelocity(vel);
};

/// @brief 
/// A function to add a linearImpulse to a object for moving to right 
/// @param objectId
/// Identifier for ObjectID
void PhysicsFacade::MoveRight(const int objectId)
{
	b2Body* body = findBody(objectId);
	const PhysicsBody* ob = getPhysicsObject(objectId);
	//body->ApplyLinearImpulse(b2Vec2(ob->getSpeed(), Y_AXIS_STATIC), body->GetWorldCenter(), true);

	b2Vec2 vel = body->GetLinearVelocity();
	vel.y = ob->getLinearVelocity();
	vel.x = ob->getSpeed();
	body->SetLinearVelocity(vel);
};

//in Step()

/// @brief 
/// A function to add a linearImpulse to a object for jumping
/// @param objectId 
/// Identifier for ObjectID
void PhysicsFacade::Jump(const int objectId)
{
  	b2Body* body = findBody(objectId);
	const PhysicsBody* ob = getPhysicsObject(objectId);

	b2Vec2 vel = body->GetLinearVelocity();
	vel.y = ob->getJumpHeight() * -1;
	body->SetLinearVelocity(vel);
};