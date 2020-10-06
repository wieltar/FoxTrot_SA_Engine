#include "PhysicsFacade.h"


/// @brief Constructor
PhysicsFacade::PhysicsFacade()
{

}

/// @brief Destructor
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
	for (const auto& value : bodies) {
		if (value.first->getSpriteID() == objectId)
		{
			return value.first;
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
	float halfH = object.getHeight()/ 2;
	float halfW = object.getWidth() / 2;
	float posY = object.getPositionY() - object.getHeight() / 2;
	float posX = object.getPositionX() + object.getWidth() / 2;
	shape.SetAsBox(halfW, halfH, b2Vec2(posX, posY), object.getRotation());
	return shape;
}

/// @brief 
/// @param Object 
void PhysicsFacade::addStaticObject(PhysicsBody* object) {
	b2BodyDef groundBodyDef;
	b2Body* body = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox = createShape(*object);
	body->CreateFixture(&groundBox, 0.0f);
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
	fixtureDef.density = object->getDensity();
	fixtureDef.friction = object->getFriction();
	fixtureDef.restitution = object->getRestitution();

	body->CreateFixture(&fixtureDef);
	auto x = body->GetPosition();

	bodyDef.position.Set(object->getPositionX(), object->getPositionY());

	cout << "Pushing back obj: spriteid: " << object->getSpriteID() << endl;
	bodies.insert(std::pair<PhysicsBody*, b2Body*>(object, body));
}

/// @brief 
/// @param objectId 
b2Body* PhysicsFacade::findBody(int objectId) {
	for (const auto& value : bodies) {
		if (value.first->getSpriteID() == objectId)
		{
			return value.second;
		}
	}
	return NULL;
	// throw error?
}

/// @brief 
void PhysicsFacade::update() {
	this->world.Step(timeStep, velocityIterations, positionIterations);

	for (auto const& it : bodies)
	{
		b2Body* body = it.second;
		PhysicsBody* object = it.first;
		b2Vec2 position = body->GetPosition();
		float angle = body->GetAngle();
		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
		object->setPositionX(body->GetWorldCenter().x - object->getWidth() / 2);
		object->setPositionY(body->GetWorldCenter().y + object->getHeight() / 2);
		//TODO from radiant to radius/angle???
		object->setRotation(body->GetAngle());
	}
}

/// @brief 
/// @param objectId 
void PhysicsFacade::MoveLeft(int objectId)
{
	b2Body* body = findBody(objectId);
	PhysicsBody* ob = getPhysicsObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob->getSpeed() * -1, Y_AXIS_STATIC), body->GetWorldCenter(), true);
};

/// @brief 
/// @param objectId 
void PhysicsFacade::MoveRight(int objectId)
{
	b2Body* body = findBody(objectId);
	PhysicsBody* ob = getPhysicsObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob->getSpeed(), Y_AXIS_STATIC), body->GetWorldCenter(), true);
};

/// @brief 
/// @param objectId 
void PhysicsFacade::Jump(int objectId)
{
	b2Body* body = findBody(objectId);
	PhysicsBody* ob = getPhysicsObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(X_AXIS_STATIC, ob->getJumpHeight() * -1), body->GetWorldCenter(), true);
};

/// @brief 
/// @param objectId 
void PhysicsFacade::JumpLeft(int objectId)
{
	b2Body* body = findBody(objectId);
	PhysicsBody* ob = getPhysicsObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob->getSpeed() * INCREASE_JUMP_SPEED * -1, ob->getJumpHeight() * -1), body->GetWorldCenter(), true);
};

/// @brief 
/// @param objectId 
void PhysicsFacade::JumpRight(int objectId)
{
	b2Body* body = findBody(objectId);
	PhysicsBody* ob = getPhysicsObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob->getSpeed() * INCREASE_JUMP_SPEED, ob->getJumpHeight() * -1), body->GetWorldCenter(), true);
};