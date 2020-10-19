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
	engine.eventManager.notify(EventType::MOVE, new Object());

	engine.createNewSceneWithSceneID(1);
	
	engine.loadSprite(1, "../Assets/Sprites/World/LIGHT TILE WITHOUT TOP.png", 16, 16, 1);

	engine.loadSprite(100, "../Assets/Sprites/Character/adventure.png", 37, 50, 1);
	engine.loadSprite(101, "../Assets/Sprites/Character/adventure_air_attack1.png", 37, 50, 4);
	engine.loadSprite(102, "../Assets/Sprites/Character/adventure_run.png", 37, 50, 6);
	engine.loadSprite(103, "../Assets/Sprites/Character/adventure_slide.png", 37, 50, 2);

	Object* object = new Object();
	object->setName("character");
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
	object->registerSprite("default", 100);
	object->registerSprite("air_attack", 101);
	object->registerSprite("run", 102);
	object->registerSprite("slide", 103);
	object->changeToState("run");
	engine.createObject(1, object);

	Object* staticGround = new Object();
	staticGround->registerSprite("default", 1);
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


	engine.stopTickThreads();
	bool gameRunning = true;
	while (gameRunning)
	{
		for (int i = 0; i < 100; i++)
		{
			this_thread::sleep_for(chrono::milliseconds(50));
		}
		gameRunning = false
	}

	return 0;
}