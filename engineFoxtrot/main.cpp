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

	engine.addEventListener(new PhysicsEngine, EventType::MOVE);
	engine.eventManager.notify(EventType::MOVE, new Object);

	engine.createNewSceneWithSceneID(1);
	engine.createNewSceneWithSceneID(2);
	//engine.createNewSceneWithSceneID(3);
	engine.createNewSceneWithSceneID(20);

	engine.createNewObjectWithSceneID(1, 1, 50, 5, 40, 40, false);
	engine.setCurrentScene(1);

	engine.createNewObjectWithSceneID(2, 1, 50, 5, 40, 40, false);
	//engine.createNewObjectWithSceneID(2, 2, 100, 5, 40, 40, false);
	//engine.createNewObjectWithSceneID(2, 3, 150, 5, 40, 40, false);
	//engine.createNewObjectWithSceneID(2, 4, 5, 50, 40, 40, false);
	//engine.createNewObjectWithSceneID(2, 5, 50, 50, 40, 40, false);
	//engine.createNewObjectWithSceneID(2, 6, 100, 50, 40, 40, false);
	//engine.createNewObjectWithSceneID(2, 7, 150, 50, 40, 40, false);
	//engine.createNewObjectWithSceneID(2, 8, 5, 100, 40, 40, false);
	//engine.createNewObjectWithSceneID(2, 9, 100, 100, 40, 40, false);
	//engine.createNewObjectWithSceneID(2, 10, 50, 100, 40, 40, false);


	engine.linkSpriteIDWithAssetPath(1, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-00.png");
	engine.linkSpriteIDWithAssetPath(2, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-01.png");
	//engine.linkSpriteIDWithAssetPath(3, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-02.png");
	//engine.linkSpriteIDWithAssetPath(4, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-03.png");
	//engine.linkSpriteIDWithAssetPath(5, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-00.png");
	//engine.linkSpriteIDWithAssetPath(6, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-01.png");
	//engine.linkSpriteIDWithAssetPath(7, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-02.png");
	//engine.linkSpriteIDWithAssetPath(8, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-03.png");
	//engine.linkSpriteIDWithAssetPath(9, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-04.png");
	//engine.linkSpriteIDWithAssetPath(10, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/helmet_02a.png");

	//engine.createNewSceneWithSceneID(20);
	engine.createNewObjectWithSceneID(20, 1, 50, 150, 40, 40, false);
	engine.createNewObjectWithSceneID(20, 2, 20, 300, 40, 40, true);
	engine.setCurrentScene(20);
	////engine.createNewObjectWithSceneID(20, 1, 30, 0, 40, 40, false,100,400,1,0,0);
	//engine.createNewObjectWithSceneID(20, 1, 50, 5, 40, 40, false);


	/*Object* object = new Object(10);
	object->setName("house");
	object->setHeight(80);
	object->setWidth(80);
	object->setPositionX(30);
	object->setPositionY(0); 
	object->setSpeed(100);
	object->setJumpHeight(400);
	object->setDensity(1);
	object->setFriction(0);
	object->setRestitution(0);
	object->setStatic(false);
	engine.createObject(3, object);

	Object* staticGround = new Object(11);
	staticGround->setWidth(500); // width
	staticGround->setHeight(10);// height
	staticGround->setPositionX(20); // x 20 left down
	staticGround->setPositionY(300);// y 300 left down
	staticGround->setStatic(true);
	engine.createObject(3, staticGround);*/

	//engine.linkSpriteIDWithAssetPath(1, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-attack1-00.png");
	engine.physicsEngine.registerObjectInCurrentVectorWithPhysicsEngine();
	cout << "Got to here " << endl;
	this_thread::sleep_for(chrono::milliseconds(100));
	engine.startTickThreads();


	
	//engine.startTickThreads();

	//for (int i = 0; i < 100; i++)
	//{
	//	engine.moveObjectTo(1, i, 10);
	//	this_thread::sleep_for(chrono::milliseconds(10));
	//}

	////for (int32 i = 0; i < 1000; ++i)
	////{
	////	engine.phy->MoveRight(1);
	////	engine.phy->update();

	////	float x = i;
	////	printf("counter: %4.2f xPos: %4.2f yPos: %4.2f \n", x, o->getPositionX(), o->getPositionY());
	////	engine.sviEngine.testLoopVideo(*o, *g);

	////	SDL_Delay(10);
	////}
	this_thread::sleep_for(chrono::milliseconds(5000));

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



	return 0;
}