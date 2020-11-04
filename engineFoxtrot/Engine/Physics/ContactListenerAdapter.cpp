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
		map<int, vector<Direction>> direction = getCollisionDirection(result);

		EventSingleton::get_instance().dispatchEvent<OnCollisionBeginEvent>((Event&)OnCollisionBeginEvent(result.object1->getObjectId(), result.object2->getObjectId(), direction));
	}
}

map<int, vector<Direction>> ContactListenerAdapter::getCollisionDirection(CollisionStruct result) {
	map<int, vector<Direction>> direction;
	auto object1minY = result.object1->getPositionY();
	auto object1minX = result.object1->getPositionX();

	auto object2minY = result.object2->getPositionY();
	auto object2minX = result.object2->getPositionX();

	auto obj1 = vector<Direction>();
	auto obj2 = vector<Direction>();

	if (result.object1->getYAxisVelocity() != 0 || result.object2->getYAxisVelocity() != 0) {
		if (object1minY < object2minY) {
			obj1.push_back(Direction::DOWN);
			obj2.push_back(Direction::UP);
		}
		if (object1minY > object2minY) {
			obj1.push_back(Direction::UP);
			obj2.push_back(Direction::DOWN);
		}
	}
	else {
		if (object1minX < object2minX) {
			obj1.push_back(Direction::RIGHT);
			obj2.push_back(Direction::LEFT);
		}
		if (object1minX > object2minX) {
			obj1.push_back(Direction::LEFT);
			obj2.push_back(Direction::RIGHT);
		}
	}
	direction.insert(pair<int, vector<Direction>>(result.object1->getObjectId(), obj1));
	direction.insert(pair<int, vector<Direction>>(result.object2->getObjectId(), obj2));
	return direction;
}

/// @brief 
/// Fires Event when a contact between two objects end
/// @overrides box2dContactListener
void ContactListenerAdapter::EndContact(b2Contact* contact) {
	b2Fixture* fixtureOne = contact->GetFixtureA();
	b2Fixture* fixtureTwo = contact->GetFixtureB();

	auto result = facade->getObjectsByFixture(fixtureOne, fixtureTwo);
	if (result.object1 != nullptr && result.object2 != nullptr) {

		map<int, vector<Direction>> direction = getCollisionDirection(result);

		EventSingleton::get_instance().dispatchEvent<OnCollisionEndEvent>((Event&)OnCollisionEndEvent(result.object1->getObjectId(), result.object2->getObjectId(), direction));
	}
};

