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
	/*
	engine.addEventListener(new PhysicsEngine, EventType::MOVE);
	engine.eventManager.notify(EventType::MOVE, new Object(1));

	engine.createNewSceneWithSceneID(1);
	
	SpriteObject so0(1, 16, 16, 1);
	SpriteObject so1(100, 37, 50, 1);
	SpriteObject so2(101, 37, 50, 4);
	SpriteObject so3(102, 37, 50, 6);
	SpriteObject so4(103, 37, 50, 2);
	SpriteObject so5(104, 37, 50, 2);


	engine.loadSprite(so0, "../Assets/Sprites/World/LIGHT TILE WITHOUT TOP.png");

	engine.loadSprite(so1, "../Assets/Sprites/Character/adventure.png");
	engine.loadSprite(so2, "../Assets/Sprites/Character/adventure_air_attack1.png");
	engine.loadSprite(so3, "../Assets/Sprites/Character/adventure_run.png");
	engine.loadSprite(so4, "../Assets/Sprites/Character/adventure_slide.png"); 
	engine.loadSprite(so5, "../Assets/Sprites/Character/adventure_fall.png");*/

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

	Scene* testScene = new Scene(3);

	Object* object = new Object(1);
	object->setHeight(200);
	object->setWidth(200);
	object->setPositionX(30);
	object->setPositionY(80);
	object->setSpeed(100);
	object->setJumpHeight(400);
	object->setDensity(10);
	object->setFriction(0);
	object->setRestitution(0);
	object->setStatic(false);
	/*object->registerSprite("default", so1);
	object->registerSprite("air_attack", so2);
	object->registerSprite("run", so3);
	object->registerSprite("slide", so4);
	object->registerSprite("air_fall", so5);
	object->changeToState("air_fall");

	engine.createObject(1, object);

	Object* staticGround = new Object(2);
	staticGround->registerSprite("default", so0);*/

	testScene->addNewObjectToLayer(1, object);
	
	Object* object2 = new Object(2);
	object2->setName("person");
	object2->setHeight(80);
	object2->setWidth(80);
	object2->setPositionX(100);
	object2->setPositionY(80);
	object2->setSpeed(100000);
	object2->setJumpHeight(4000000);
	object2->setDensity(10);
	object2->setFriction(0);
	object2->setRestitution(0);
	object2->setStatic(false);
	testScene->addNewObjectToLayer(1, object2);

	Object* staticGround = new Object(101);
	staticGround->setWidth(500); // width
	staticGround->setHeight(10);// height
	staticGround->setPositionX(20); // x 20 left down
	staticGround->setPositionY(300);// y 300 left down
	staticGround->setStatic(true);
	staticGround->changeToState("default");
	engine.createObject(1, staticGround);

	engine.setCurrentScene(1);
	engine.physicsEngine.registerObjectInCurrentVectorWithPhysicsEngine();
	testScene->addNewObjectToLayer(1, staticGround);
	
	engine.insertScene(testScene);
	engine.insertScene(new Scene(4));

	engine.configureInput(KEY_A, new MoveLeft);
	engine.configureInput(KEY_D, new MoveRight);
	engine.configureInput(KEY_SPACE, new Jump);

	engine.setCurrentScene(3);
	engine.startTickThreads();
}

int main() {
	sceneTestSetup();

	engine.startTickThreads();
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
