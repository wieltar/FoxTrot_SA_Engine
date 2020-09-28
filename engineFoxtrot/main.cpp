#pragma once
#include <iostream>
#include "Engine.h"
#include "Scene.h"
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

// TODO : Set object folder up with interface route

Engine engine;

void engineTick(Engine & engine) {
	while (1) {
		this_thread::sleep_for(chrono::milliseconds(17));

		engine.receiveTick();
	}
}

int main() {
	
	thread t1(engineTick,std::ref(engine));
	t1.detach();
	
	
	engine.createNewSceneWithSceneID(10);
	engine.createNewSceneWithSceneID(1);

	// Object testing purpose
	// TODO: remove after testing
	engine.createNewObjectWithSceneID(1, 1, 50, 5, 40, 40);

	engine.createNewObjectWithSceneID(10, 1, 50, 5, 40, 40);
	engine.createNewObjectWithSceneID(10, 2, 100, 5, 40, 40);
	engine.createNewObjectWithSceneID(10, 3, 150, 5, 40, 40);
	engine.createNewObjectWithSceneID(10, 4, 5, 50, 40, 40);
	engine.createNewObjectWithSceneID(10, 5, 50, 5, 40, 40);
	engine.createNewObjectWithSceneID(10, 6, 100, 50, 40, 40);
	engine.createNewObjectWithSceneID(10, 7, 150, 50, 40, 40);
	engine.createNewObjectWithSceneID(10, 8, 5, 6, 40, 40);
	engine.createNewObjectWithSceneID(10, 9, 5, 100, 40, 40);
	engine.createNewObjectWithSceneID(10, 10, 50, 100, 40, 40);
	
	engine.setCurrentScene(10);

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

	
	SDL_Delay(5000);
	engine.setCurrentScene(1);


	engine.addEventListener(new PhysicsEngine, EventType::MOVE);
	engine.eventManager.notify(EventType::MOVE, new Object);

	//engine.svi.load("../Assets/Sound/b423b42.wav");
	//engine.svi.play();
	
	while (1) {}
	t1.join();
}


