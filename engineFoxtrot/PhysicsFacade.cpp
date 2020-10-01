
#include "PhysicsFacade.h"


PhysicsFacade::PhysicsFacade()
{
	
}

PhysicsFacade::~PhysicsFacade()
{
	// Delete bodies
	// Delete world
}


//TODO update method position for each object
//TODO mapping between id and object

Object PhysicsFacade::getObject(int objectId) {
	for (const auto& value : temp) {
		if (value.getId() == objectId) {
			return value;
		}
	}
	return NULL;
}

void PhysicsFacade::addGround() {
	b2BodyDef groundBodyDef;
	b2Body* groundBody = world.CreateBody(&groundBodyDef);


	b2PolygonShape groundBox;
	groundBox.SetAsBox(50, 50, b2Vec2(200, 200), 0);
	groundBody->CreateFixture(&groundBox, 0.0f);
}

void PhysicsFacade::registerRectangle(Object object) {
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	b2Body* body = world.CreateBody(&bodyDef);


	objectData data;
	data.id = object.getId();

	//body->SetUserData(&object);

	b2PolygonShape bodyBox;
	bodyBox.SetAsBox(object.getWidth() / 2, object.getHeight() /2, b2Vec2(object.getX() - object.getWidth()/2, 0), 0);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &bodyBox;
	fixtureDef.density = object.getDensity();
	fixtureDef.friction = object.getFriction();
	fixtureDef.restitution = object.getRestitution();

	body->CreateFixture(&fixtureDef);
}

b2Body* PhysicsFacade::findBody(int objectId) {
	b2Body* temp = this->world.GetBodyList();
	temp = temp->GetNext();
	auto x = temp->GetPosition();
	while (temp)
	{
		return temp;
		objectData* data = (objectData*)temp->GetUserData().pointer;
		if (data->id == objectId) {
			return temp;
		}
	}
}

void PhysicsFacade::MoveLeft(int objectId) 
{
	b2Body* body = findBody(objectId);
	Object ob = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob.getSpeed() * -1, 0.0f), body->GetWorldCenter(), true);
	ob.setX(body->GetPosition().x);
	ob.setY(body->GetPosition().y);
}
void PhysicsFacade::MoveRight(int objectId)
{
	b2Body* body = findBody(objectId);
	Object ob = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob.getSpeed(), 0.0f), body->GetWorldCenter(), true);
	ob.setX(body->GetPosition().x);
	ob.setY(body->GetPosition().y);
}
void PhysicsFacade::Jump(int objectId)
{
	b2Body* body = findBody(objectId);
	Object ob = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(0, ob.getJumpHeight() * -1), body->GetWorldCenter(), true);
	ob.setX(body->GetPosition().x);
	ob.setY(body->GetPosition().y);
}
void PhysicsFacade::JumpLeft(int objectId)
{
	b2Body* body = findBody(objectId);
	Object ob = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob.getSpeed() * 10 * -1, ob.getJumpHeight() * -1), body->GetWorldCenter(), true);
	ob.setX(body->GetPosition().x);
	ob.setY(body->GetPosition().y);
};
void PhysicsFacade::JumpRight(int objectId) 
{
	b2Body* body = findBody(objectId);
	Object ob = getObject(objectId);
	body->ApplyLinearImpulse(b2Vec2(ob.getSpeed() *  10, ob.getJumpHeight() * -1), body->GetWorldCenter(), true);
	ob.setX(body->GetPosition().x);
	ob.setY(body->GetPosition().y);
};