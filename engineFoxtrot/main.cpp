#pragma once
#include <iostream>
#include "Engine.h"
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

Engine engine;

int main() {
	//house
	Object* o = new Object(1);
	o->setName("house");
	o->setHeight(80);
	o->setWidth(80);
	o->setPositionX(30);
	o->setPositionY(0);

	o->setSpeed(100);
	o->setJumpHeight(400);
	o->setDensity(1);
	o->setFriction(0);
	o->setRestitution(0);

	engine.phy->temp.push_back(o);
	engine.phy->registerRectangle(*o);

	Object* g = new Object();
	g->setWidth(500); // width
	g->setHeight(10);// height
	g->setPositionX(20); // x 20 left down
	g->setPositionY(300);// y 300 left down

	engine.phy->addGround(*g);


	for (int32 i = 0; i < 1000; ++i)
	{
		engine.phy->MoveRight(1);
		engine.phy->update();

		float x = i;
		printf("counter: %4.2f xPos: %4.2f yPos: %4.2f \n", x, o->getPositionX(), o->getPositionY());
		engine.svi.testLoopVideo(*o, *g);

		SDL_Delay(10);
	}

	engine.addEventListener(new PhysicsEngine, EventType::MOVE);
	engine.eventManager.notify(EventType::MOVE, new Object);

	engine.createNewSceneWithSceneID(2);
	engine.createNewSceneWithSceneID(1);

	engine.createNewObjectWithSceneID(1, 1, 50, 5, 40, 40);
	engine.startTickThreads();
	
	engine.createNewObjectWithSceneID(2, 1, 50, 5, 40, 40);
	engine.createNewObjectWithSceneID(2, 2, 100, 5, 40, 40);
	engine.createNewObjectWithSceneID(2, 3, 150, 5, 40, 40);
	engine.createNewObjectWithSceneID(2, 4, 5, 50, 40, 40);
	engine.createNewObjectWithSceneID(2, 5, 50, 50, 40, 40);
	engine.createNewObjectWithSceneID(2, 6, 100, 50, 40, 40);
	engine.createNewObjectWithSceneID(2, 7, 150, 50, 40, 40);
	engine.createNewObjectWithSceneID(2, 8, 5, 100, 40, 40);
	engine.createNewObjectWithSceneID(2, 9, 100, 100, 40, 40);
	engine.createNewObjectWithSceneID(2, 10, 50, 100, 40, 40);
	
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
	
	engine.setCurrentScene(2);
	this_thread::sleep_for(chrono::milliseconds(250));
	engine.createNewSceneWithSceneID(10);
	engine.setCurrentScene(10);
	this_thread::sleep_for(chrono::milliseconds(1000));
	engine.setCurrentScene(2);
	cout << "Engine filled" << endl;
	
	this_thread::sleep_for(chrono::milliseconds(2500));
	for (int i = 0; i < 10; i++)
	{
		if(i % 2)engine.setCurrentScene(1);
		else engine.setCurrentScene(2);
		this_thread::sleep_for(chrono::milliseconds(50));
	}

	engine.setCurrentScene(1);
	
	for (int i = 0; i < 100; i++)
	{
		engine.moveObjectTo(1, i, 10);
		this_thread::sleep_for(chrono::milliseconds(10));
	}

	for (int i = 0; i < 360; i++)
	{
		engine.setObjectRotation(1, i);
		this_thread::sleep_for(chrono::milliseconds(10));
	}
	engine.setCurrentScene(1);
	engine.stopTickThreads();


	

	while (1) {}

}


