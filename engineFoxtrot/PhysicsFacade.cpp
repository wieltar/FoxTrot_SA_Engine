
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

void PhysicsFacade::addGround(GroundData g) {
	b2BodyDef groundBodyDef;
	b2Body* groundBody = world.CreateBody(&groundBodyDef);


	b2PolygonShape groundBox;
	float halfH = g.hy / 2;
	float halfW = g.hx / 2;
	float posX = g.x - halfW / 2;
	float posY = g.y - halfH / 2;

	groundBox.SetAsBox(halfH, halfW, b2Vec2(posX, posY), 0);

	groundBody->CreateFixture(&groundBox, 0.0f);

}

void PhysicsFacade::registerRectangle(Object* object) {
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	b2Body* body = world.CreateBody(&bodyDef);

	b2PolygonShape bodyBox;
	bodyBox.SetAsBox(object->getWidth() / 2, 
					object->getHeight() / 2, 
						b2Vec2(
								object->getX() - object->getWidth()/2, 
								object->getY() - object->getHeight()/2
						),
					0);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &bodyBox;
	fixtureDef.density = object->getDensity();
	fixtureDef.friction = object->getFriction();
	fixtureDef.restitution = object->getRestitution();
	
	body->CreateFixture(&fixtureDef);
	auto x = body->GetPosition();

	this->bodies.insert(std::pair<int, b2Body*>(object->getId(), body));
}

b2Body* PhysicsFacade::findBody(int objectId) {
	if (bodies.count(objectId) > 0) {
		return bodies.at(objectId);
	}
}

void PhysicsFacade::update() {
	this->world.Step(timeStep, velocityIterations, positionIterations);

	std::map<int, b2Body*>::iterator it;

	for (it = bodies.begin(); it != bodies.end(); it++)
	{
		b2Body* b = it->second;

		Object* ob = this->getObject(it->first);

		ob->setX(b->GetWorldCenter().x);
		ob->setY(b->GetWorldCenter().y);
	}

}

void PhysicsFacade::MoveLeft(int objectId)
{
	b2Body* body = findBody(objectId);
	Object* ob = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob->getSpeed() * -1, 0.0f), body->GetWorldCenter(), true);
};

void PhysicsFacade::MoveRight(int objectId)
{
	b2Body* body = findBody(objectId);
	Object* ob = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob->getSpeed(), 0.0f), body->GetWorldCenter(), true);
};

void PhysicsFacade::Jump(int objectId)
{
	b2Body* body = findBody(objectId);
	Object* ob = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(0, ob->getJumpHeight() * -1), body->GetWorldCenter(), true);
};

void PhysicsFacade::JumpLeft(int objectId)
{
	b2Body* body = findBody(objectId);
	Object* ob = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob->getSpeed() * 10 * -1, ob->getJumpHeight() * -1), body->GetWorldCenter(), true);
};

void PhysicsFacade::JumpRight(int objectId) 
{
	b2Body* body = findBody(objectId);
	Object* ob = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob->getSpeed() *  10, ob->getJumpHeight() * -1), body->GetWorldCenter(), true);
};