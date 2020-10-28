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

void sceneTestSetup()
{
	SpriteObject so0(1, 16, 16, 1, "../Assets/Sprites/World/LIGHT TILE WITHOUT TOP.png");
	SpriteObject so1(100, 37, 50, 1, "../Assets/Sprites/Character/adventure.png");
	SpriteObject so2(101, 37, 50, 4, "../Assets/Sprites/Character/adventure_air_attack1.png");
	SpriteObject so3(102, 37, 50, 6, "../Assets/Sprites/Character/adventure_run.png");
	SpriteObject so4(103, 37, 50, 2, "../Assets/Sprites/Character/adventure_slide.png");
	SpriteObject so5(104, 37, 50, 2, "../Assets/Sprites/Character/adventure_fall.png");


	engine.loadSprite(so0);

	engine.loadSprite(so1);
	engine.loadSprite(so2);
	engine.loadSprite(so3);
	engine.loadSprite(so4); 
	engine.loadSprite(so5);

	Scene* testScene = new Scene(3);

	Object* object = new Object(1);
	object->setName("person1");
	object->setHeight(100);
	object->setWidth(100);
	object->setPositionX(30);
	object->setPositionY(300);
	object->setSpeed(100);
	object->setJumpHeight(400);
	object->setDensity(10);
	object->setFriction(0);
	object->setRestitution(0);
	object->setStatic(false);
	object->registerSprite("default", so1);
	object->registerSprite("air_attack", so2);
	object->registerSprite("run", so3);
	object->registerSprite("slide", so4);
	object->registerSprite("air_fall", so5);
	object->changeToState("run");

	testScene->addNewObjectToLayer(1, object);
	
	Object* object2 = new Object(2);
	object2->setName("person2");
	object2->setHeight(80);
	object2->setWidth(80);
	object2->setPositionX(200);
	object2->setPositionY(80);
	object2->setSpeed(100000);
	object2->setJumpHeight(4000000);
	object2->setDensity(10);
	object2->setFriction(0);
	object2->setRestitution(0);
	object2->setStatic(false);
	object2->registerSprite("default", so1);
	object2->registerSprite("air_attack", so2);
	object2->registerSprite("run", so3);
	object2->registerSprite("slide", so4);
	object2->registerSprite("air_fall", so5);
	object2->changeToState("air_fall");
	testScene->addNewObjectToLayer(1, object2);

	Object* staticGround = new Object(101);
	staticGround->setScalable(true);
	staticGround->setWidth(500); // width
	staticGround->setHeight(10);// height
	staticGround->setPositionX(20); // x 20 left down
	staticGround->setPositionY(300);// y 300 left down
	staticGround->setStatic(true);
	staticGround->registerSprite("default", so0);
	staticGround->changeToState("default");
	testScene->addNewObjectToLayer(1, staticGround);


	engine.insertScene(testScene);
	engine.setCurrentScene(3);
	engine.physicsEngine.registerObjectInCurrentVectorWithPhysicsEngine();
	
	engine.insertScene(new Scene(4));

	engine.configureInput(KEY_A, new MoveLeft);
	engine.configureInput(KEY_D, new MoveRight);
	engine.configureInput(KEY_SPACE, new Jump);

	engine.setCurrentScene(3);
	engine.startTickThreads();
}

int main() {
	sceneTestSetup();

	bool gameRunning = true;
	while (gameRunning)
	{
		AppTickEvent60 appTick;
		AppTickEvent30 appTick30;

		engine.pollInput();
		EventSingleton::get_instance().dispatchEvent<AppTickEvent60>(appTick);
		EventSingleton::get_instance().dispatchEvent<AppTickEvent30>(appTick30);


		this_thread::sleep_for(chrono::milliseconds(10));
	}
	engine.stopTickThreads();

	return 0;
}
