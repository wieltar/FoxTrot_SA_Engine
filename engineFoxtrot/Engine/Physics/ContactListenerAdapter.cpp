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

		map<int, Direction> direction = getCollisionDirection(contact, getCollidedBeginByObject(collidedPoint, result.object1),
			getCollidedBeginByObject(collidedPoint, result.object2));

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

		map<int, Direction> direction = getCollisionDirection(contact, getCollidedEndByObject(collidedPoint, result.object1),
			getCollidedEndByObject(collidedPoint, result.object2));

		EventSingleton::get_instance().dispatchEvent<OnCollisionEndEvent>((Event&)OnCollisionEndEvent(result.object1->getObjectId(), result.object2->getObjectId(), direction));
	}
};


/// @brief 
/// When a contact begins gets the direction of where the collision happend on the object
pair<int, Direction> ContactListenerAdapter::getCollidedBeginByObject(b2Vec2 collidedPoint, PhysicsBody* object) {
	if (object->getPositionY() < collidedPoint.y) {
		return pair<int, Direction>(object->getObjectId(), Direction::DOWN);
	}
	else if (object->getPositionY() > collidedPoint.y) {
		return pair<int, Direction>(object->getObjectId(), Direction::UP);
	}
	if (object->getPositionX() < collidedPoint.x) {
		return pair<int, Direction>(object->getObjectId(), Direction::LEFT);
	}
	else if (object->getPositionX() > collidedPoint.x) {
		return pair<int, Direction>(object->getObjectId(), Direction::RIGHT);
	}
	return pair<int, Direction>();
}

/// @brief 
/// When a contact ends gets the direction of where the collision happend on the object
pair<int, Direction> ContactListenerAdapter::getCollidedEndByObject(b2Vec2 collidedPoint, PhysicsBody* object) {
	if (object->getPositionY() < collidedPoint.y) {
		return pair<int, Direction>(object->getObjectId(), Direction::UP);
	}
	else if (object->getPositionY() > collidedPoint.y) {
		return pair<int, Direction>(object->getObjectId(), Direction::DOWN);
	}
	if (object->getPositionX() < collidedPoint.x) {
		return pair<int, Direction>(object->getObjectId(), Direction::LEFT);
	}
	else if (object->getPositionX() > collidedPoint.x) {
		return pair<int, Direction>(object->getObjectId(), Direction::RIGHT);
	}
	return pair<int, Direction>();
}

/// @brief 
/// Returns the box2d vector (x, y) on what point the collision happend
b2Vec2 ContactListenerAdapter::getCollidedPoint(b2Contact* contact) {
	b2WorldManifold worldManifold;
	contact->GetWorldManifold(&worldManifold);
	return worldManifold.points[0];
}

/// @brief 
/// Returns a map <int, Direction> with the ID of an object and the side where the collision happend
map<int, Direction> ContactListenerAdapter::getCollisionDirection(b2Contact* contact, pair<int, Direction> pairObject1, pair<int, Direction> pairObject2) {
	map<int, Direction> direction = map<int, Direction>();
	direction.insert(pairObject1);
	direction.insert(pairObject2);
	return direction;
}