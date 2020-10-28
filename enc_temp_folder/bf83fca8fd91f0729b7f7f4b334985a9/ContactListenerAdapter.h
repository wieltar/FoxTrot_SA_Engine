#pragma once

class ContactListenerAdapter : public b2ContactListener
{
private:
	PhysicsFacade* facade;
public:
	ContactListenerAdapter(PhysicsFacade* _facade) : facade(_facade) { }
protected:
	void BeginContact(b2Contact* contact) override {
		b2Fixture* fixtureOne = contact->GetFixtureA();
		b2Fixture* fixtureTwo = contact->GetFixtureB();
		auto result = facade->getObjectsByFixture(fixtureOne, fixtureTwo);
		if (result.object1 != nullptr && result.object2 != nullptr) {
			std::cout << "BEGIN === Ob1: " << result.object1->getSpriteID() << "  Obj2: " << result.object2->getSpriteID() << std::endl;
			EventSingleton::get_instance().dispatchEvent<OnCollisionBeginEvent>((Event&)OnCollisionBeginEvent(result.object1->getSpriteID(), result.object2->getSpriteID()));
		}
	}

	void EndContact(b2Contact* contact) override {
		b2Fixture* fixtureOne = contact->GetFixtureA();
		b2Fixture* fixtureTwo = contact->GetFixtureB();

		b2WorldManifold worldManifold;
		auto manifold = contact->GetManifold();
		worldManifold.Initialize(manifold, fixtureOne->GetBody()->GetTransform(), fixtureOne->GetShape()->m_radius, 
			fixtureTwo->GetBody()->GetTransform(), fixtureTwo->GetShape()->m_radius);



		auto result = facade->getObjectsByFixture(fixtureOne, fixtureTwo);
		if (result.object1 != nullptr && result.object2 != nullptr) {

			for (auto ele : manifold->points)
			{
				if (ele.localPoint.y > result.object1->getPositionY()) {
					std::cout << "OBJECT 1: TOP" << std::endl;
				}
				else if (ele.localPoint.y < result.object1->getPositionY()) {
					std::cout << "OBJECT 1: BOTTOM" << std::endl;
				}
				if (ele.localPoint.y > result.object2->getPositionY()) {
					std::cout << "OBJECT 2: TOP" << std::endl;
				}
				else if (ele.localPoint.y < result.object2->getPositionY()) {
					std::cout << "OBJECT 2: BOTTOM" << std::endl;
				}
			}
			std::cout << std::endl;
			std::cout << "END ==== Ob1: " << result.object1->getSpriteID() << "  Obj2: " << result.object2->getSpriteID() << std::endl;
			EventSingleton::get_instance().dispatchEvent<OnCollisionEndEvent>((Event&)OnCollisionEndEvent(result.object1->getSpriteID(), result.object2->getSpriteID()));
		}
	}
};