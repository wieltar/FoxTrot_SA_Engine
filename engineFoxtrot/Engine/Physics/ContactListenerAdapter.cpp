#include "stdafx.h"
#include "ContactListenerAdapter.h"

/// @brief 
/// Fires Event when a contact between two objects begin
/// @overrides box2dContactListener
void ContactListenerAdapter::BeginContact(b2Contact* contact) {
	b2Fixture* fixtureOne = contact->GetFixtureA();
	b2Fixture* fixtureTwo = contact->GetFixtureB();
	auto result = facade->getObjectsByFixture(fixtureOne, fixtureTwo);
	if (result.object1 != nullptr && result.object2 != nullptr) {
		auto collidedPoint = getCollidedPoint(contact);

		map<int, vector<Direction>> direction;
		direction.insert(pair<int, vector<Direction>>(result.object1->getObjectId(), getCollidedBeginByObject(collidedPoint, result.object1)));
		direction.insert(pair<int, vector<Direction>>(result.object2->getObjectId(), getCollidedBeginByObject(collidedPoint, result.object2)));

		EventSingleton::get_instance().dispatchEvent<OnCollisionBeginEvent>((Event&)OnCollisionBeginEvent(result.object1->getObjectId(), result.object2->getObjectId(), direction));
	}
}

/// @brief 
/// Fires Event when a contact between two objects end
/// @overrides box2dContactListener
void ContactListenerAdapter::EndContact(b2Contact* contact) {
	b2Fixture* fixtureOne = contact->GetFixtureA();
	b2Fixture* fixtureTwo = contact->GetFixtureB();

	auto result = facade->getObjectsByFixture(fixtureOne, fixtureTwo);
	if (result.object1 != nullptr && result.object2 != nullptr) {
		auto collidedPoint = getCollidedPoint(contact);

		map<int, vector<Direction>> direction;
		direction.insert(pair<int, vector<Direction>>(result.object1->getObjectId(), getCollidedEndByObject(collidedPoint, result.object1)));
		direction.insert(pair<int, vector<Direction>>(result.object2->getObjectId(), getCollidedEndByObject(collidedPoint, result.object2)));

		EventSingleton::get_instance().dispatchEvent<OnCollisionEndEvent>((Event&)OnCollisionEndEvent(result.object1->getObjectId(), result.object2->getObjectId(), direction));
	}
};


/// @brief 
/// When a contact begins gets the direction of where the collision happend on the object
vector<Direction> ContactListenerAdapter::getCollidedBeginByObject(b2Vec2 collidedPoint, PhysicsBody* object) {
	auto ret = vector<Direction>();
	if (round(object->getPositionY()) <= round(collidedPoint.y)) {
		ret.push_back(Direction::DOWN);
	}
	else if (round(object->getPositionY()) >= round(collidedPoint.y)) {
		ret.push_back(Direction::UP);
	}
	if (round(object->getPositionX()) <= round(collidedPoint.x)) {
		ret.push_back(Direction::RIGHT);
	}
	if (round(object->getPositionX()) >= round(collidedPoint.x)) {
		ret.push_back(Direction::LEFT);
	}
	return ret;
}

/// @brief 
/// When a contact ends gets the direction of where the collision happend on the object
vector<Direction> ContactListenerAdapter::getCollidedEndByObject(b2Vec2 collidedPoint, PhysicsBody* object) {
	auto ret = vector<Direction>();
	if (round(object->getPositionY()) <= round(collidedPoint.y)) {
		ret.push_back(Direction::UP);
	}
	else if (round(object->getPositionY()) >= round(collidedPoint.y)) {
		ret.push_back(Direction::DOWN);
	}
	if (round(object->getPositionX()) <= round(collidedPoint.x)) {
		ret.push_back(Direction::LEFT);
	}
	if (round(object->getPositionX()) >= round(collidedPoint.x)) {
		ret.push_back(Direction::RIGHT);
	}
	return ret;
}

/// @brief 
/// Returns the box2d vector (x, y) on what point the collision happend
b2Vec2 ContactListenerAdapter::getCollidedPoint(b2Contact* contact) {
	b2WorldManifold worldManifold;
	contact->GetWorldManifold(&worldManifold);
	return worldManifold.points[0];
}