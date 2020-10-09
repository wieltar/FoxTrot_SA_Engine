#pragma once
#include <iostream>
#include "Engine.h"
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

// Korte uitleg over Pointers van deze branch
// https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-2/

// Auto_ptr DEPRECATED
// Wanneer iets een Auto_ptr is blijft er maar 1 eigenaar. Bij het doorpasen van de ptr verliest de vorige pointer zijn eigenschap op deze pointer.
// Auto_ptr is deprecated
// It takes ownership of the pointer in a way that no two pointers should contain the same object. 
// Assignment transfers ownership and resets the rvalue auto pointer to a null pointer. 
// Thus, they can’t be used within STL containers due to the aforementioned inability to be copied.

// Unique_ptr
// std::unique_ptr was developed in C++11 as a replacement for std::auto_ptr.
// It explicitly prevents copying of its contained pointer as would happen with normal assignment i.e. it allows exactly one owner of the underlying pointer.
// So, when using unique_ptr there can only be at most one unique_ptr at any one resource and when that unique_ptr is destroyed, the resource is automatically claimed. 
// Also, since there can only be one unique_ptr to any resource, so any attempt to make a copy of unique_ptr will cause a compile-time error.
// So, it’s best to use unique_ptr when we want a single pointer to an object that will be reclaimed when that single pointer is destroyed.
// Use unique_ptr when you want to have single ownership(Exclusive) of the resource. Only one unique_ptr can point to one resource. 
// Since there can be one unique_ptr for single resource its not possible to copy one unique_ptr to another.

// Shared_ptr
// A shared_ptr is a container for raw pointers. It is a reference counting ownership model i.e. it maintains the reference count of its contained pointer in cooperation with all copies of the shared_ptr.
// So, the counter is incremented each time a new pointer points to the resource and decremented when the destructor of the object is called.
// Use shared_ptr if you want to share ownership of a resource. Many shared_ptr can point to a single resource.
// shared_ptr maintains reference count for this propose. when all shared_ptr’s pointing to resource goes out of scope the resource is destroyed.


// Weak_ptr
// A weak_ptr is created as a copy of shared_ptr. It provides access to an object that is owned by one or more shared_ptr instances but does not participate in reference counting.
// The existence or destruction of weak_ptr has no effect on the shared_ptr or its other copies. 
// It is required in some cases to break circular references between shared_ptr instances.
// When you do want to refer to your object from multiple places – 
// for those references for which it’s ok to ignoreand deallocate(so they’ll just note the object is gone when you try to dereference).

// Gebruikt references in plaats van pointers. Dit zorgt ervoor dat je niet perongeluk de pointer aanpast. 

// Const correctness
// https://www.studytonight.com/cpp/const-keyword.php


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
	engine.createNewSceneWithSceneID(3);
	engine.createNewSceneWithSceneID(20);

	engine.createNewObjectWithSceneID(1, 1, 50, 50, 40, 40, false);
	engine.setCurrentScene(1);

	engine.createNewObjectWithSceneID(2, 1, 50, 50, 40, 40, false);
	engine.createNewObjectWithSceneID(2, 2, 100, 50, 40, 40, false);
	engine.createNewObjectWithSceneID(2, 3, 150, 50, 40, 40, false);
	engine.createNewObjectWithSceneID(2, 4, 5, 50, 40, 40, false);
	engine.createNewObjectWithSceneID(2, 5, 50, 50, 40, 40, false);
	engine.createNewObjectWithSceneID(2, 6, 100, 50, 40, 40, false);
	engine.createNewObjectWithSceneID(2, 7, 150, 50, 40, 40, false);
	engine.createNewObjectWithSceneID(2, 8, 5, 100, 40, 40, false);
	engine.createNewObjectWithSceneID(2, 9, 100, 100, 40, 40, false);
	engine.createNewObjectWithSceneID(2, 10, 50, 100, 40, 40, false);


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

	engine.createNewSceneWithSceneID(20);
	engine.createNewObjectWithSceneID(20, 1, 50, 150, 40, 40, false);
	engine.createNewObjectWithSceneID(20, 2, 20, 300, 40, 40, true);
	engine.setCurrentScene(20);
	engine.createNewObjectWithSceneID(20, 1, 30, 50, 40, 40, false,100,400,1,0,0);
	engine.createNewObjectWithSceneID(20, 1, 50, 55, 40, 40, false);

	engine.linkSpriteIDWithAssetPath(101, "../Assets/Sprites/Project assets/LIGHT TILE WITHOUT TOP.png");
	Object* object = new Object(10);
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
	object->setSpriteID(1);
	engine.createObject(3, object);

	Object* staticGround = new Object(11);
	staticGround->setWidth(500); // width
	staticGround->setHeight(10);// height
	staticGround->setPositionX(20); // x 20 left down
	staticGround->setPositionY(300);// y 300 left down
	staticGround->setStatic(true);
	staticGround->setSpriteID(101);
	engine.createObject(3, staticGround);


	engine.setCurrentScene(3);
	engine.physicsEngine.registerObjectInCurrentVectorWithPhysicsEngine();
	engine.startTickThreads();
	for (int i = 0; i < 100; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(50));
	}


	cout << "Got to here " << endl;
	this_thread::sleep_for(chrono::milliseconds(100));


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
		engine.moveObjectTo(1, i, 100);
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