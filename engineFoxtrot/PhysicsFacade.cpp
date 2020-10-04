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

//TODO update method position for each object
//TODO mapping between id and object

Object* PhysicsFacade::getObject(int objectId) {
	for (const auto& value : temp) {
		if (value->getId() == objectId) {
			return value;
		}
	}
	return NULL;
}

void PhysicsFacade::addGround(Object& g) {
	b2BodyDef groundBodyDef;
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	b2PolygonShape groundBox;
	float halfH = g.getHeight() / 2;
	float halfW = g.getWidth() / 2;
	float posY = g.getPositionY() - halfH;
	float posX = g.getPositionX() + halfW;
	groundBox.SetAsBox(halfW, halfH, b2Vec2(posX, posY), g.getAngle());
	groundBody->CreateFixture(&groundBox, 0.0f);
}



void PhysicsFacade::registerRectangle(Object& object) {
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	b2Body* body = world.CreateBody(&bodyDef);

	b2PolygonShape bodyBox;
	bodyBox.SetAsBox(object.getWidth() / 2,
					object.getHeight() / 2,
						b2Vec2(
							object.getPositionX() + object.getWidth() / 2,
							object.getPositionY() - object.getHeight() / 2
						),
					object.getAngle());

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &bodyBox;
	fixtureDef.density = object.getDensity();
	fixtureDef.friction = object.getFriction();
	fixtureDef.restitution = object.getRestitution();

	body->CreateFixture(&fixtureDef);
	auto x = body->GetPosition();

	this->bodies.insert(std::pair<int, b2Body*>(object.getId(), body));
}



b2Body* PhysicsFacade::findBody(int objectId) {
	if (bodies.count(objectId) > 0) {
		return bodies.at(objectId);
	}
}

void PhysicsFacade::update() {
	this->world.Step(timeStep, velocityIterations, positionIterations);

	for (auto const& it : bodies)
	{
		this->currentBody = it.second;
		this->currentObject = this->getObject(it.first);

		this->currentObject->setPositionX(this->currentBody->GetWorldCenter().x - this->currentObject->getWidth() / 2);
		this->currentObject->setPositionY(this->currentBody->GetWorldCenter().y + this->currentObject->getHeight() / 2);
		this->currentObject->setAngle(this->currentBody->GetAngle());
	}
}

void PhysicsFacade::MoveLeft(int objectId)
{
	this->currentBody = findBody(objectId);
	this->currentObject = getObject(objectId);
	this->currentBody->ApplyLinearImpulse(b2Vec2(this->currentObject->getSpeed() * -1, 0.0f), this->currentBody->GetWorldCenter(), true);
};

void PhysicsFacade::MoveRight(int objectId)
{
	this->currentBody = findBody(objectId);
	this->currentObject = getObject(objectId);
	this->currentBody->ApplyLinearImpulse(b2Vec2(this->currentObject->getSpeed(), 0.0f), this->currentBody->GetWorldCenter(), true);
};

void PhysicsFacade::Jump(int objectId)
{
	this->currentBody = findBody(objectId);
	this->currentObject = getObject(objectId);
	this->currentBody->ApplyLinearImpulse(b2Vec2(0, this->currentObject->getJumpHeight() * -1), this->currentBody->GetWorldCenter(), true);
};

void PhysicsFacade::JumpLeft(int objectId)
{
	this->currentBody = findBody(objectId);
	this->currentObject = getObject(objectId);
	this->currentBody->ApplyLinearImpulse(b2Vec2(this->currentObject->getSpeed() * 10 * -1, this->currentObject->getJumpHeight() * -1), this->currentBody->GetWorldCenter(), true);
};

void PhysicsFacade::JumpRight(int objectId)
{
	this->currentBody = findBody(objectId);
	this->currentObject = getObject(objectId);
	this->currentBody->ApplyLinearImpulse(b2Vec2(this->currentObject->getSpeed() * 10, this->currentObject->getJumpHeight() * -1), this->currentBody->GetWorldCenter(), true);
};