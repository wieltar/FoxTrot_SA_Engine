#pragma once
#include "stdafx.h"
#include "../Engine/Engine.h"
#include "../Engine/Events/AppTickEvent30.h"
#include "../Engine/Events/AppTickEvent60.h"

#include "Events/Window/WindowCloseEvent.h"

// TODO engine.h & engine.cpp

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

Engine engine;

class Player : public Object {
private:
	bool canJump = false;
public:
	Player() : Object(2) {
		this->setName("person");
		this->setHeight(80);
		this->setWidth(80);
		this->setPositionX(100);
		this->setPositionY(80);

		this->setSpeed(50);
		this->setJumpHeight(400);
		this->setDensity(100);
		this->setFriction(0);
		this->setRestitution(0);
		this->setStatic(false);

		this->setRotatable(true);

		EventSingleton::get_instance().setEventCallback<OnCollisionBeginEvent>(BIND_EVENT_FN(Player::onCollisionBeginEvent));
		EventSingleton::get_instance().setEventCallback<OnCollisionEndEvent>(BIND_EVENT_FN(Player::onCollisionEndEvent));
		EventSingleton::get_instance().setEventCallback<KeyPressedEvent>(BIND_EVENT_FN(Player::onKeyPressed));
	}

	/// @brief 
	/// Handles when an collision event begins, when the direction of the collision happend on the bottom side of the player object, set can jump true
	void onCollisionBeginEvent(Event& event) {
		auto collisionEvent = static_cast<OnCollisionBeginEvent&>(event);
		if (collisionEvent.GetObjectOneId() != this->getSpriteID() && collisionEvent.GetObjectTwoId() != this->getSpriteID()) return;

		auto map = collisionEvent.getDirectionMap();
		auto collidedDirection = map[this->getSpriteID()];
		if (collidedDirection == Direction::DOWN) {
			this->canJump = true;
		}
	}

	/// @brief 
	/// Handles when an collision event ends, when the direction of the collision happend on the bottom side of the player object, set can jump false
	void onCollisionEndEvent(Event& event) {
		auto collisionEvent = static_cast<OnCollisionEndEvent&>(event);
		if (collisionEvent.GetObjectOneId() != this->getSpriteID() && collisionEvent.GetObjectTwoId() != this->getSpriteID()) return;

		auto map = collisionEvent.getDirectionMap();
		auto collidedDirection = map[this->getSpriteID()];
		if (collidedDirection == Direction::DOWN) {
			this->canJump = false;
		}
	}

	/// @brief 
	/// Handles when an key pressed event happend, Player can move right, left and jump
	void onKeyPressed(Event& event) {
		auto keyPressedEvent = static_cast<KeyPressedEvent&>(event);

		switch (keyPressedEvent.GetKeyCode())
		{
		case KeyCode::KEY_A:
			EventSingleton::get_instance().dispatchEvent<ActionEvent>((Event&)ActionEvent(Direction::LEFT, this->getSpriteID()));
			break;
		case KeyCode::KEY_D:
			EventSingleton::get_instance().dispatchEvent<ActionEvent>((Event&)ActionEvent(Direction::RIGHT, this->getSpriteID()));
			break;
		case KeyCode::KEY_SPACE:
			if (canJump) {
				EventSingleton::get_instance().dispatchEvent<ActionEvent>((Event&)ActionEvent(Direction::UP, this->getSpriteID()));
			}
			break;
		default:
			break;
		}
	}
};

void sceneTestSetup()
{
	engine.createNewSceneWithSceneID(3);

	engine.linkSpriteIDWithAssetPath(1, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-00.png");
	engine.linkSpriteIDWithAssetPath(2, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-01.png");
	engine.linkSpriteIDWithAssetPath(3, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-02.png");
	engine.linkSpriteIDWithAssetPath(4, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-03.png");
	engine.linkSpriteIDWithAssetPath(5, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-00.png");
	engine.linkSpriteIDWithAssetPath(6, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-01.png");
	engine.linkSpriteIDWithAssetPath(7, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-02.png");
	engine.linkSpriteIDWithAssetPath(8, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-03.png");
	engine.linkSpriteIDWithAssetPath(9, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-04.png");
	engine.linkSpriteIDWithAssetPath(10, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/helmet_02a.png");
	engine.linkSpriteIDWithAssetPath(101, "../Assets/Sprites/Project assets/LIGHT TILE WITHOUT TOP.png");
	engine.linkSpriteIDWithAssetPath(102, "../Assets/Sprites/Project assets/LIGHT TILE WITHOUT TOP.png");

	Object* object = new Object(1);
	object->setName("house");
	object->setHeight(80);
	object->setWidth(80);
	object->setPositionX(30);
	object->setPositionY(80);
	object->setSpeed(100);
	object->setJumpHeight(400);
	object->setDensity(1000000);
	object->setFriction(0);
	object->setRestitution(0);
	object->setStatic(false);
	engine.createObject(3, object);

	Object* object2 = new Player();
	engine.createObject(3, object2);

	Object* staticGround = new Object(101);
	staticGround->setWidth(500); // width
	staticGround->setHeight(10);// height
	staticGround->setPositionX(20); // x 20 left down
	staticGround->setPositionY(300);// y 300 left down
	staticGround->setStatic(true);
	staticGround->setFriction(0);
	engine.createObject(3, staticGround);

	Object* staticGround2 = new Object(102);
	staticGround2->setWidth(100); // width
	staticGround2->setHeight(80);// height
	staticGround2->setPositionX(220); // x 20 left down
	staticGround2->setPositionY(290);// y 300 left down
	staticGround2->setStatic(true);
	staticGround2->setFriction(0);
	engine.createObject(3, staticGround2);

	engine.setCurrentScene(3);
	engine.physicsEngine.registerObjectInCurrentVectorWithPhysicsEngine();
}

int main() {
	sceneTestSetup();

	bool gameRunning = true;
	while (gameRunning)
	{
		AppTickEvent60 appTick;
		AppTickEvent30 appTick30;

		engine.pollEvents();
		EventSingleton::get_instance().dispatchEvent<AppTickEvent60>(appTick);
		EventSingleton::get_instance().dispatchEvent<AppTickEvent30>(appTick30);

		this_thread::sleep_for(chrono::milliseconds(10));
	}

	return 0;
}
