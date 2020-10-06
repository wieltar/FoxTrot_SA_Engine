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
Object* PhysicsFacade::getObject(int objectId) {
	for (const auto& value : temp) {
		if (value->getId() == objectId) {
			return value;
		}
	}
	return NULL;
}

/// @brief 
/// @param objectId 
b2PolygonShape createShape(Object& object) {
	b2PolygonShape shape;
	//BOX2D needs coordinates off CENTER CENTER position and you get the LEFT BOTTOM
	//SDL2 needs coordinates off LEFT TOP position and you get the LEFT BOTTOM
	float halfH = object.getHeight() / 2;
	float halfW = object.getWidth() / 2;
	float posY = object.getPositionY() - object.getHeight() / 2;
	float posX = object.getPositionX() + object.getWidth() / 2;
	shape.SetAsBox(halfW, halfH, b2Vec2(posX, posY), object.getAngle());
	return shape;
}

/// @brief 
/// @param Object 
void PhysicsFacade::addStaticObject(Object& ground) {
	b2BodyDef groundBodyDef;
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox = createShape(ground);
	groundBody->CreateFixture(&groundBox, 0.0f);
}

/// @brief 
/// @param Object 
void PhysicsFacade::registerRectangle(Object& object) {
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	b2Body* body = world.CreateBody(&bodyDef);

	b2PolygonShape bodyBox = createShape(object);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &bodyBox;
	fixtureDef.density = object.getDensity();
	fixtureDef.friction = object.getFriction();
	fixtureDef.restitution = object.getRestitution();

	body->CreateFixture(&fixtureDef);

	this->bodies.insert(std::pair<int, b2Body*>(object.getId(), body));
}

/// @brief 
/// @param objectId 
b2Body* PhysicsFacade::findBody(int objectId) {
	if (bodies.count(objectId) > 0) {
		return bodies.at(objectId);
	}
}

/// @brief 
void PhysicsFacade::update() {
	this->world.Step(timeStep, velocityIterations, positionIterations);

	for (auto const& it : bodies)
	{
		b2Body* body = it.second;
		Object* object = this->getObject(it.first);

		object->setPositionX(body->GetWorldCenter().x - object->getWidth() / 2);
		object->setPositionY(body->GetWorldCenter().y + object->getHeight() / 2);
		object->setAngle(body->GetAngle());
	}
}

/// @brief 
/// @param objectId 
void PhysicsFacade::MoveLeft(int objectId)
{
	b2Body* body = findBody(objectId);
	Object* object = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(object->getSpeed() * -1, Y_AXIS_STATIC), body->GetWorldCenter(), true);
};

/// @brief 
/// @param objectId 
void PhysicsFacade::MoveRight(int objectId)
{
	b2Body* body = findBody(objectId);
	Object* object = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(object->getSpeed(), Y_AXIS_STATIC), body->GetWorldCenter(), true);
};

/// @brief 
/// @param objectId 
void PhysicsFacade::Jump(int objectId)
{
	b2Body* body = findBody(objectId);
	Object* object = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(X_AXIS_STATIC, object->getJumpHeight() * -1), body->GetWorldCenter(), true);
};

/// @brief 
/// @param objectId 
void PhysicsFacade::JumpLeft(int objectId)
{
	b2Body* body = findBody(objectId);
	Object* object = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(object->getSpeed() * INCREASE_JUMP_SPEED * -1, object->getJumpHeight() * -1), body->GetWorldCenter(), true);
};

/// @brief 
/// @param objectId 
void PhysicsFacade::JumpRight(int objectId)
{
	b2Body* body = findBody(objectId);
	Object* object = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(object->getSpeed() * INCREASE_JUMP_SPEED, object->getJumpHeight() * -1), body->GetWorldCenter(), true);
};