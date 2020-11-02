#pragma once
#include "stdafx.h"
#include "Glitch.h"
#include "Level.h"
#include "SpriteState.h"

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
		this->setRotatable(false);

		EventSingleton::get_instance().setEventCallback<OnCollisionBeginEvent>(BIND_EVENT_FN(Player::onCollisionBeginEvent));
		EventSingleton::get_instance().setEventCallback<OnCollisionEndEvent>(BIND_EVENT_FN(Player::onCollisionEndEvent));
		EventSingleton::get_instance().setEventCallback<KeyPressedEvent>(BIND_EVENT_FN(Player::onKeyPressed));
	}

	/// @brief 
	/// Handles when an collision event begins, when the direction of the collision happend on the bottom side of the player object, 
	/// set can jump true
	void onCollisionBeginEvent(Event& event) {
		auto collisionEvent = static_cast<OnCollisionBeginEvent&>(event);
		if (collisionEvent.GetObjectOneId() != this->getObjectId() && collisionEvent.GetObjectTwoId() != this->getObjectId()) return;

		auto map = collisionEvent.getDirectionMap();
		auto collidedDirection = map[this->getObjectId()];

		if (std::find(collidedDirection.begin(), collidedDirection.end(), Direction::DOWN) != collidedDirection.end()) {
			this->canJump = true;
			this->changeToState(SpriteState::DEFAULT);
		}
	}

	/// @brief 
	/// Handles when an collision event ends, when the direction of the collision happend on the bottom side of the player object, set can jump false
	void onCollisionEndEvent(Event& event) {
		auto collisionEvent = static_cast<OnCollisionEndEvent&>(event);
		if (collisionEvent.GetObjectOneId() != this->getObjectId() && collisionEvent.GetObjectTwoId() != this->getObjectId()) return;

		auto map = collisionEvent.getDirectionMap();
		auto collidedDirection = map[this->getObjectId()];

		if (std::find(collidedDirection.begin(), collidedDirection.end(), Direction::DOWN) != collidedDirection.end()) {
			this->canJump = false;
		}
	}

	void setYAxisVelocity(const float val) override {

		if (!canJump) {
			if (val > 0 && !changed) {
				this->changeToState(SpriteState::AIR_FALL);
			}
		}

		if (val == 0) {
			changed = false;
		}


		Object::setYAxisVelocity(val);
	}

	/// @brief 
	/// Handles when an key pressed event happend, Player can move right, left and jump
	void onKeyPressed(Event& event) {
		auto keyPressedEvent = static_cast<KeyPressedEvent&>(event);

		switch (keyPressedEvent.GetKeyCode())
		{
		case KeyCode::KEY_A:
			EventSingleton::get_instance().dispatchEvent<ActionEvent>((Event&)ActionEvent(Direction::LEFT, this->getObjectId()));
			if (canJump)
				this->changeToState(SpriteState::RUN_LEFT);
			break;
		case KeyCode::KEY_D:
			EventSingleton::get_instance().dispatchEvent<ActionEvent>((Event&)ActionEvent(Direction::RIGHT, this->getObjectId()));
			if (canJump)
				this->changeToState(SpriteState::RUN_RIGHT);
			break;
		case KeyCode::KEY_SPACE:
			if (canJump) {
				this->changeToState(SpriteState::AIR_JUMP);
				EventSingleton::get_instance().dispatchEvent<ActionEvent>((Event&)ActionEvent(Direction::UP, this->getObjectId()));
			}
			break;
		default:
			break;
		}
	}
};

void sceneTestSetup()
{
	SpriteObject* so0 = new SpriteObject(1, 16, 16, 1, 300, "Assets/Sprites/World/LIGHT TILE WITHOUT TOP.png");
	SpriteObject* so1 = new SpriteObject(100, 37, 50, 1, 100, "Assets/Sprites/Character/adventure.png");
	SpriteObject* so2 = new SpriteObject(101, 37, 50, 4, 100, "Assets/Sprites/Character/adventure_air_attack1.png");
	SpriteObject* so3 = new SpriteObject(102, 37, 50, 6, 100, "Assets/Sprites/Character/adventure_run_right.png");
	SpriteObject* so4 = new SpriteObject(103, 37, 50, 2, 100, "Assets/Sprites/Character/adventure_slide.png");
	SpriteObject* so5 = new SpriteObject(104, 37, 50, 2, 100, "Assets/Sprites/Character/adventure_fall.png");
	SpriteObject* so6 = new SpriteObject(105, 37, 50, 2, 100, "Assets/Sprites/Character/adventure_jump.png");
	SpriteObject* so7 = new SpriteObject(106, 37, 50, 6, 100, "Assets/Sprites/Character/adventure_run_left.png");

	engine.loadSprite(*so0);
	engine.loadSprite(*so1);
	engine.loadSprite(*so2);
	engine.loadSprite(*so3);
	engine.loadSprite(*so4);
	engine.loadSprite(*so5);
	engine.loadSprite(*so6);
	engine.loadSprite(*so7);

	map<string, string> soundL1 = {
		{"Level_1_Sound", "Assets/Sound/file_example_WAV_1MG.wav"},
	};

	Level* testScene = new Level(100, soundL1);

	Object* object = new Object(1);
	object->setName("person1");
	object->setHeight(100);
	object->setWidth(100);
	object->setPositionX(30);
	object->setPositionY(300);
	object->setSpeed(100);
	object->setJumpHeight(400);
	object->setDensity(1000000);
	object->setFriction(0);
	object->setRestitution(0);
	object->setStatic(false);

	object->registerSprite(SpriteState::DEFAULT, so1);
	object->changeToState(SpriteState::DEFAULT);
	testScene->addNewObjectToLayer(1, object);

	Object* object2 = new Player();
	object2->setStatic(false);
	object2->registerSprite(SpriteState::DEFAULT, so1);
	object2->registerSprite(SpriteState::AIR_ATTACK, so2);
	object2->registerSprite(SpriteState::RUN_RIGHT, so3);
	object2->registerSprite(SpriteState::SLIDE, so4);
	object2->registerSprite(SpriteState::AIR_FALL, so5);
	object2->registerSprite(SpriteState::AIR_JUMP, so6);
	object2->registerSprite(SpriteState::RUN_LEFT, so7);
	object2->changeToState(SpriteState::DEFAULT);
	testScene->addNewObjectToLayer(1, object2);


	Object* staticGround = new Object(101);
	staticGround->setScalable(true);
	staticGround->setWidth(500); // width
	staticGround->setHeight(10);// height
	staticGround->setPositionX(20); // x 20 left down
	staticGround->setPositionY(300);// y 300 left down
	staticGround->setStatic(true);
	staticGround->registerSprite(SpriteState::DEFAULT, so0);
	staticGround->changeToState(SpriteState::DEFAULT);
	testScene->addNewObjectToLayer(1, staticGround);

	SpriteObject* particle1Sprite = new SpriteObject(11, 20, 20, 20, 300, "Assets/Particles/fire.png");
	engine.loadSprite(*particle1Sprite);

	ParticleAdapter* particle1 = new ParticleAdapter(11);        // create a new particle system pointer
	particle1->registerSprite(SpriteState::DEFAULT, particle1Sprite);
	particle1->changeToState(SpriteState::DEFAULT);
	particle1->setPosition(800, 384);              // set the position
	particle1->setStyle(ParticleInit::FIRE);    // set the example effects
	particle1->setStartSpin(0);
	particle1->setStartSpinVar(90);
	particle1->setEndSpin(90);
	particle1->setStartSpinVar(90);

	testScene->addNewObjectToLayer(4, particle1);

	ParticleAdapter* particle2 = new ParticleAdapter(11);        // create a new particle system pointer
	particle2->registerSprite(SpriteState::DEFAULT, particle1Sprite);
	particle2->changeToState(SpriteState::DEFAULT);
	particle2->setPosition(100, 384);              // set the position
	particle2->setStyle(ParticleInit::EXPLOSION);    // set the example effects
	particle2->setStartSpin(0);
	particle2->setStartSpinVar(90);
	particle2->setEndSpin(90);
	particle2->setStartSpinVar(90);

	testScene->addNewObjectToLayer(2, particle2);

	Object* staticGround2 = new Object(102);
	staticGround2->setWidth(100); // width
	staticGround2->setHeight(80);// height
	staticGround2->setPositionX(220); // x 20 left down
	staticGround2->setPositionY(290);// y 300 left down
	staticGround2->setStatic(true);
	staticGround2->setFriction(0);
	staticGround2->registerSprite(SpriteState::DEFAULT, so0);
	staticGround2->changeToState(SpriteState::DEFAULT);
	testScene->addNewObjectToLayer(1, staticGround2);

	Object* staticGround3 = new Object(119);
	staticGround3->setScalable(true);
	staticGround3->setWidth(30); // width
	staticGround3->setHeight(80);// height
	staticGround3->setPositionX(360); // x 20 left down
	staticGround3->setPositionY(290);// y 300 left down
	staticGround3->setStatic(true);
	staticGround3->registerSprite(SpriteState::DEFAULT, so0);
	staticGround3->changeToState(SpriteState::DEFAULT);
	testScene->addNewObjectToLayer(1, staticGround3);

	Object* staticGround4 = new Object(120);
	staticGround4->setScalable(true);
	staticGround4->setWidth(30); // width
	staticGround4->setHeight(140);// height
	staticGround4->setPositionX(480); // x 20 left down
	staticGround4->setPositionY(290);// y 300 left down
	staticGround4->setStatic(true);
	staticGround4->registerSprite(SpriteState::DEFAULT, so0);
	staticGround4->changeToState(SpriteState::DEFAULT);
	testScene->addNewObjectToLayer(1, staticGround4);

	engine.configureInput(KeyCode::KEY_A, engine.makeCommand<MoveLeft>());
	engine.configureInput(KeyCode::KEY_D, engine.makeCommand<MoveRight>());
	engine.configureInput(KeyCode::KEY_SPACE, engine.makeCommand<Jump>());
	engine.configureInput(KeyCode::KEY_F1, engine.makeCommand<ToggleFps>(), true);
	//Engine* command = engine.makeCommand<Engine>();

	engine.insertScene(testScene);
	engine.setCurrentScene(100);
	testScene->Start();

	engine.startTickThreads();
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
	engine.stopTickThreads();

	return 0;
}