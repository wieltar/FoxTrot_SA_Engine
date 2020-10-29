#pragma once
#include "./Events/Action/ActionEvent.h"
#include <map>
class ContactListenerAdapter : public b2ContactListener
{
private:
	PhysicsFacade* facade;
public:
	ContactListenerAdapter(PhysicsFacade* _facade) : facade(_facade) { }
protected:
	std::map<int, Direction> GetCollidedDirectionTopDown(b2ManifoldPoint contactPoint, PhysicsBody* object) {
		std::map<int, Direction> direction = std::map<int, Direction>();
		if (contactPoint.localPoint.y > object->getPositionY()) {
			std::cout << "OBJECT " << object->getSpriteID() << " BOTTOM COLLISION" << std::endl;
			direction.insert(std::pair<int, Direction>(object->getSpriteID(), Direction::DOWN));
		}
		else if (contactPoint.localPoint.y < object->getPositionY()) {
			std::cout << "OBJECT " << object->getSpriteID() << " TOP COLLISION" << std::endl;
			direction.insert(std::pair<int, Direction>(object->getSpriteID(), Direction::UP));
		}
		return direction;
	}
	std::map<int, Direction> GetCollidedDirectionRightLeft(b2ManifoldPoint contactPoint, PhysicsBody* object) {
		std::map<int, Direction> direction = std::map<int, Direction>();

		if (contactPoint.localPoint.x > object->getPositionX()) {
			std::cout << "OBJECT " << object->getSpriteID() << " LEFT COLLISION" << std::endl;
			direction.insert(std::pair<int, Direction>(object->getSpriteID(), Direction::LEFT));
		}
		else if (contactPoint.localPoint.x < object->getPositionX()) {
			std::cout << "OBJECT " << object->getSpriteID() << " RIGHT COLLISION" << std::endl;
			direction.insert(std::pair<int, Direction>(object->getSpriteID(), Direction::RIGHT));
		}
		return direction;
	}

	void BeginContact(b2Contact* contact) override {
		b2Fixture* fixtureOne = contact->GetFixtureA();
		b2Fixture* fixtureTwo = contact->GetFixtureB();
		auto result = facade->getObjectsByFixture(fixtureOne, fixtureTwo);
		if (result.object1 != nullptr && result.object2 != nullptr) {
			auto manifold = contact->GetManifold();

			auto f = contact->GetFriction();
			auto object1 = result.object1;
			auto object2 = result.object2;

			float oldY = 0;
			float oldX = 0;
			bool shouldCheckTopDown = false;
			bool shouldCheckRightLeft = false;

			b2WorldManifold worldManifold;
			contact->GetWorldManifold(&worldManifold);
			b2Vec2 collPoint = worldManifold.points[0];

			std::map<int, Direction> direction = std::map<int, Direction>();
			if (object1->getPositionY() < collPoint.y) {
				direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::DOWN));
			}
			else if (object1->getPositionY() > collPoint.y) {
				direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::UP));
			}
			if (object1->getPositionX() < collPoint.x) {
				direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::LEFT));
			}
			else if (object1->getPositionX() > collPoint.x) {
				direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::RIGHT));
			}

			if (object2->getPositionY() < collPoint.y) {
				direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::DOWN));
			}
			else if (object2->getPositionY() > collPoint.y) {
				direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::UP));
			}
			if (object2->getPositionX() < collPoint.x) {
				direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::LEFT));
			}
			else if (object2->getPositionX() > collPoint.x) {
				direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::RIGHT));
			}

 		//	for (auto e : contact->GetManifold()->points) {
			//	if (oldY == e.localPoint.y) {
			//		shouldCheckTopDown = true;
			//	}
			//	if (oldX == e.localPoint.x) {
			//		shouldCheckRightLeft = true;
			//	}
			//	oldY = e.localPoint.y;
			//	oldX = e.localPoint.x;
			//}

			//std::map<int, Direction> direction = std::map<int, Direction>();

			//if (shouldCheckRightLeft) {
			//	if (object1->getPositionX() < object2->getPositionX()) {
			//		std::cout << "OBJECT " << object1->getSpriteID() << " right COLLISION" << std::endl;
			//		std::cout << "OBJECT " << object2->getSpriteID() << " left COLLISION" << std::endl;
			//		direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::LEFT));
			//		direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::RIGHT));
			//	}
			//	if (object1->getPositionX() > object2->getPositionX()) {
			//		std::cout << "OBJECT " << object1->getSpriteID() << " left COLLISION" << std::endl;
			//		std::cout << "OBJECT " << object2->getSpriteID() << " right COLLISION" << std::endl;
			//		direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::RIGHT));
			//		direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::LEFT));
			//	}
			//}
			//if (shouldCheckTopDown) {
			//	if (object1->getPositionY() < object2->getPositionY()) {
			//		std::cout << "OBJECT " << object1->getSpriteID() << " Bottom COLLISION" << std::endl;
			//		std::cout << "OBJECT " << object2->getSpriteID() << " Top COLLISION" << std::endl;
			//		direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::DOWN));
			//		direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::UP));
			//	}
			//	if (object1->getPositionY() > object2->getPositionY()) {
			//		std::cout << "OBJECT " << object1->getSpriteID() << " Top COLLISION" << std::endl;
			//		std::cout << "OBJECT " << object2->getSpriteID() << " Bottom COLLISION" << std::endl;
			//		direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::UP));
			//		direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::DOWN));
			//	}
			//}
			std::cout << "BEGIN === Ob1: " << result.object1->getSpriteID() << "  Obj2: " << result.object2->getSpriteID() << std::endl;
 			EventSingleton::get_instance().dispatchEvent<OnCollisionBeginEvent>((Event&)OnCollisionBeginEvent(result.object1->getSpriteID(), result.object2->getSpriteID(), direction));
		}
	}

	void EndContact(b2Contact* contact) override {
		b2Fixture* fixtureOne = contact->GetFixtureA();
		b2Fixture* fixtureTwo = contact->GetFixtureB();

		auto result = facade->getObjectsByFixture(fixtureOne, fixtureTwo);
		if (result.object1 != nullptr && result.object2 != nullptr) {
			auto manifold = contact->GetManifold();
			auto object1 = result.object1;
			auto object2 = result.object2;

			b2WorldManifold worldManifold;
			contact->GetWorldManifold(&worldManifold);
			b2Vec2 collPoint = worldManifold.points[0];

			std::map<int, Direction> direction = std::map<int, Direction>();
			if (object1->getPositionY() < collPoint.y) {
				direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::UP));
			}
			else if (object1->getPositionY() > collPoint.y) {
				direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::DOWN));
			}
			if (object1->getPositionX() < collPoint.x) {
				direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::LEFT));
			}
			else if (object1->getPositionX() > collPoint.x) {
				direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::RIGHT));
			}

			if (object2->getPositionY() < collPoint.y) {
				direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::UP));
			}
			else if (object2->getPositionY() > collPoint.y) {
				direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::DOWN));
			}
			if (object2->getPositionX() < collPoint.x) {
				direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::LEFT));
			}
			else if (object2->getPositionX() > collPoint.x) {
				direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::RIGHT));
			}
			//int oldY = 0;
			//int oldX = 0;
			//bool shouldCheckTopDown = false;
			//bool shouldCheckRightLeft = false;
			//for (auto e : contact->GetManifold()->points) {
			//	if (oldY == e.localPoint.y) {
			//		shouldCheckTopDown = true;
			//	}
			//	if (oldX == e.localPoint.x) {
			//		shouldCheckRightLeft = true;
			//	}
			//	oldY = e.localPoint.y;
			//	oldX = e.localPoint.x;
			//}


			//std::map<int, Direction> direction = std::map<int, Direction>();

			//if (shouldCheckRightLeft) {
			//	if (object1->getPositionX() < object2->getPositionX()) {
			//		std::cout << "OBJECT " << object1->getSpriteID() << " left COLLISION" << std::endl;
			//		std::cout << "OBJECT " << object2->getSpriteID() << " right COLLISION" << std::endl;
			//		direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::LEFT));
			//		direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::RIGHT));
			//	}
			//	if (object1->getPositionX() > object2->getPositionX()) {
			//		std::cout << "OBJECT " << object1->getSpriteID() << " right COLLISION" << std::endl;
			//		std::cout << "OBJECT " << object2->getSpriteID() << " left COLLISION" << std::endl;
			//		direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::RIGHT));
			//		direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::LEFT));
			//	}
			//}
			//if (shouldCheckTopDown) {
			//	if (object1->getPositionY() < object2->getPositionY()) {
			//		std::cout << "OBJECT " << object1->getSpriteID() << " Bottom COLLISION" << std::endl;
			//		std::cout << "OBJECT " << object2->getSpriteID() << " Top COLLISION" << std::endl;
			//		direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::DOWN));
			//		direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::UP));
			//	}
			//	if (object1->getPositionY() > object2->getPositionY()) {
			//		std::cout << "OBJECT " << object1->getSpriteID() << " Top COLLISION" << std::endl;
			//		std::cout << "OBJECT " << object2->getSpriteID() << " Bottom COLLISION" << std::endl;
			//		direction.insert(std::pair<int, Direction>(object1->getSpriteID(), Direction::UP));
			//		direction.insert(std::pair<int, Direction>(object2->getSpriteID(), Direction::DOWN));

			//	}
			//}

			std::cout << "END ==== Ob1: " << result.object1->getSpriteID() << "  Obj2: " << result.object2->getSpriteID() << std::endl;
			EventSingleton::get_instance().dispatchEvent<OnCollisionEndEvent>((Event&)OnCollisionEndEvent(result.object1->getSpriteID(), result.object2->getSpriteID(), direction));
		}
	};
};