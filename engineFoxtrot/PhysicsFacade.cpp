#include "PhysicsFacade.h"


PhysicsFacade::PhysicsFacade()
{

}

PhysicsFacade::~PhysicsFacade()
{
	// When a world leaves scope or is deleted by calling delete on a pointer, all the memory reserved for bodies, fixtures, and joints is freed.This is done to improve performanceand make your life easier.
	// However, you will need to nullify any body, fixture, or joint pointers you have because they will become invalid.
	// https://box2d.org/documentation/md__d_1__git_hub_box2d_docs_dynamics.html#autotoc_md113
}

/// @brief 
/// @param objectId 
PhysicsBody* PhysicsFacade::getPhysicsObject(int objectId)
{
	for (PhysicsBody * phyBody : physicsBodyVector)
	{
		if (phyBody->objectID == objectId)
		{
			return phyBody;
		}
	}
	return NULL;
	// throw error?
}

/// @brief 
/// @param objectId 
b2PolygonShape createShape(PhysicsBody& object) {
	b2PolygonShape shape;
	//BOX2D needs coordinates off CENTER CENTER position and you get the LEFT BOTTOM
	//SDL2 needs coordinates off LEFT TOP position and you get the LEFT BOTTOM
	float halfH = object.height / 2;
	float halfW = object.width / 2;
	float posY = object.posY - object.height / 2;
	float posX = object.posX + object.width / 2;
	shape.SetAsBox(halfW, halfH, b2Vec2(posX, posY), object.angle);
	return shape;
}

/// @brief 
/// @param Object 
void PhysicsFacade::addGround(PhysicsBody* ground) {
	b2BodyDef groundBodyDef;
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox = createShape(*ground);
	groundBody->CreateFixture(&groundBox, 0.0f);
}

/// @brief 
/// @param Object 
void PhysicsFacade::registerRectangle(PhysicsBody* object) 
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	b2Body* body = world.CreateBody(&bodyDef);

	b2PolygonShape bodyBox = createShape(*object);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &bodyBox;
	fixtureDef.density = object->density;
	fixtureDef.friction = object->friction;
	fixtureDef.restitution = object->restitution;

	body->CreateFixture(&fixtureDef);
	auto x = body->GetPosition();

	bodyDef.position.Set(object->posX, object->posY);

	object->body = body;
	cout << "Pushing back obj: spriteid: " << object->objectID << endl;
	physicsBodyVector.push_back(object);
}

/// @brief 
/// @param objectId 
b2Body* PhysicsFacade::findBody(int objectId) 
{
	for (PhysicsBody* phyBody : physicsBodyVector)
	{
		if (phyBody->objectID == objectId)
		{
			return phyBody->body;
		}
	}
	return NULL;
	// throw error?
}

/// @brief 
void PhysicsFacade::update() {
	this->world.Step(timeStep, velocityIterations, positionIterations);

	for (PhysicsBody * ob : physicsBodyVector)
	{
		b2Body* body = ob->body;
		b2Vec2 position = body->GetPosition();
		float angle = body->GetAngle();
		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
		ob->posX = body->GetWorldCenter().x - ob->width / 2;
		ob->posY = body->GetWorldCenter().y + ob->height / 2;
		ob->angle = body->GetAngle();
		MoveRight(ob->objectID);
	}
}

/// @brief 
/// @param objectId 
void PhysicsFacade::MoveLeft(int objectId)
{
	b2Body* body = findBody(objectId);
	PhysicsBody* ob = getPhysicsObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob->speed * -1, NO_MOVE_Y_LEVEL), body->GetWorldCenter(), true);
};

/// @brief 
/// @param objectId 
void PhysicsFacade::MoveRight(int objectId)
{
	b2Body* body = findBody(objectId);
	PhysicsBody* ob = getPhysicsObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob->speed, NO_MOVE_Y_LEVEL), body->GetWorldCenter(), true);
};

/// @brief 
/// @param objectId 
void PhysicsFacade::Jump(int objectId)
{
	b2Body* body = findBody(objectId);
	PhysicsBody* ob = getPhysicsObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(NO_MOVE_X_LEVEL, ob->jumpHeight * -1), body->GetWorldCenter(), true);
};

/// @brief 
/// @param objectId 
void PhysicsFacade::JumpLeft(int objectId)
{
	b2Body* body = findBody(objectId);
	PhysicsBody* ob = getPhysicsObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob->speed * INCREASE_JUMP_SPEED * -1, ob->jumpHeight * -1), body->GetWorldCenter(), true);
};

/// @brief 
/// @param objectId 
void PhysicsFacade::JumpRight(int objectId)
{
	b2Body* body = findBody(objectId);
	PhysicsBody* ob = getPhysicsObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob->speed * INCREASE_JUMP_SPEED, ob->jumpHeight * -1), body->GetWorldCenter(), true);
};