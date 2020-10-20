#include "stdafx.h"
#pragma once
#include "../Engine/Engine.h"


using namespace std;

// TODO engine.h & engine.cpp

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

Engine engine;

void sceneTestSetup()
{
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
	engine.loadSprite(so5, "../Assets/Sprites/Character/adventure_fall.png");

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
	object->registerSprite("default", so1);
	object->registerSprite("air_attack", so2);
	object->registerSprite("run", so3);
	object->registerSprite("slide", so4);
	object->registerSprite("air_fall", so5);
	object->changeToState("air_fall");

	engine.createObject(1, object);

	Object* staticGround = new Object(2);
	staticGround->registerSprite("default", so0);
	staticGround->setWidth(500); // width
	staticGround->setHeight(10);// height
	staticGround->setPositionX(20); // x 20 left down
	staticGround->setPositionY(300);// y 300 left down
	staticGround->setStatic(true);
	staticGround->changeToState("default");
	engine.createObject(1, staticGround);

	engine.setCurrentScene(1);
	engine.physicsEngine.registerObjectInCurrentVectorWithPhysicsEngine();
}

int main() {
	sceneTestSetup();

	engine.startTickThreads();
	bool gameRunning = true;
	while (gameRunning)
	{
		for (int i = 0; i < 100; i++)
		{
			this_thread::sleep_for(chrono::milliseconds(50));
		}
		gameRunning = false;
	}
	engine.stopTickThreads();

	return 0;
}