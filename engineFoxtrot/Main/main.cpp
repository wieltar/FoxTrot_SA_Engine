#pragma once
#include "stdafx.h"
#include "../Engine/Engine.h"
#include "../Engine/Events/AppTickEvent30.h"
#include "../Engine/Events/AppTickEvent60.h"

#include "Events/Window/WindowCloseEvent.h"
#include "Level.h"

// TODO engine.h & engine.cpp

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

Engine engine;

void sceneTestSetup()
{

	engine.linkSpriteIDWithAssetPath(1, "../Assets/Sprites/character/adventure.png");
	engine.linkSpriteIDWithAssetPath(2, "../Assets/Sprites/character/adventure.png");
	engine.linkSpriteIDWithAssetPath(101, "../Assets/Sprites/World/LIGHT TILE WITHOUT TOP.png");

	map<string, string> soundL1 = {
		{"Level_1_Sound", "../Assets/Sound/file_example_WAV_1MG.wav"},
	};

	Level* testScene = new Level(100, soundL1);

	Object* object = new Object(1);
	object->setName("house");
	object->setHeight(80);
	object->setWidth(80);
	object->setPositionX(30);
	object->setPositionY(80);
	object->setSpeed(100);
	object->setJumpHeight(400);
	object->setDensity(10);
	object->setFriction(0);
	object->setRestitution(0);
	object->setStatic(false);

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
	testScene->addNewObjectToLayer(1, staticGround);

	engine.insertScene(testScene);
	engine.setCurrentScene(100);
	testScene->Start(); 

	engine.configureInput(KEY_A, engine.makeCommand<MoveLeft>());
	engine.configureInput(KEY_D, engine.makeCommand<MoveRight>());
	engine.configureInput(KEY_SPACE, engine.makeCommand<Jump>());
	engine.configureInput(KEY_F1, engine.makeCommand<ToggleFps>(), true);
	//Engine* command = engine.makeCommand<Engine>();

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

	return 0;
}
