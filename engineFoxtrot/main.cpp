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
	
	engine.initScene();
	Scene scene;
	Object object;

	thread t1(engineTick,std::ref(engine));
	t1.detach();
	
	engine.sceneManager.scenes.push_back(&scene);

	scene.sceneID = 10;
	// Object testing purpose
	// TODO: remove after testing
	{
		Object object1;
		object1.spriteID = 1;
		object1.positionX = 50;
		object1.positionY = 5;
		object1.width = 40;
		object1.height = 40;
		scene.Objects.push_back(&object1);

		Object object2;
		object2.spriteID = 2;
		object2.positionX = 100;
		object2.positionY = 5;
		object2.width = 40;
		object2.height = 40;
		scene.Objects.push_back(&object2);

		Object object3;
		object3.spriteID = 3;
		object3.positionX = 150;
		object3.positionY = 5;
		object3.width = 40;
		object3.height = 40;
		scene.Objects.push_back(&object3);

		Object object4;
		object4.spriteID = 4;
		object4.positionX = 5;
		object4.positionY = 50;
		object4.width = 40;
		object4.height = 40;
		scene.Objects.push_back(&object4);

		Object object5;
		object5.spriteID = 5;
		object5.positionX = 50;
		object5.positionY = 5;
		object5.width = 40;
		object5.height = 40;
		scene.Objects.push_back(&object5);

		Object object6;
		object6.spriteID = 6;
		object6.positionX = 100;
		object6.positionY = 50;
		object6.width = 40;
		object6.height = 40;
		scene.Objects.push_back(&object6);

		Object object7;
		object7.spriteID = 7;
		object7.positionX = 150;
		object7.positionY = 50;
		object7.width = 40;
		object7.height = 40;
		scene.Objects.push_back(&object7);

		Object object8;
		object8.spriteID = 8;
		object8.positionX = 5;
		object8.positionY = 5;
		object8.width = 40;
		object8.height = 40;
		scene.Objects.push_back(&object8);

		Object object9;
		object9.spriteID = 9;
		object9.positionX = 5;
		object9.positionY = 100;
		object9.width = 40;
		object9.height = 40;
		scene.Objects.push_back(&object9);

		Object object10;
		object10.spriteID = 10;
		object10.positionX = 50;
		object10.positionY = 100;
		object10.width = 40;
		object10.height = 40;
		scene.Objects.push_back(&object10);

	}

	for (auto obj : scene.Objects) {
		cout << obj->spriteID << endl;
	}

	cout << "Address: " << (int*)&(engine.svi.pointerToObjectVector) << endl;
	try
	{
		engine.sceneManager.setCurrentScene(10);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << e << '\n';
	}
	cout << "Address: " << (int*)&(engine.svi.pointerToObjectVector) << endl;
	cout << "Size: " << engine.svi.pointerToObjectVector->size() << endl;


	//engine.svi.testLoopVideo(10,10);
	engine.svi.clearScreen();

	//engine.svi.loadImage(100, "../Assets/Sprites/Project assets/Assets/icons/48x48/fruit_01a.png");
	//engine.svi.renderCopy(100, 0, 0, 10, 10);

	engine.TESTfillSpriteVector();
	engine.loadSpriteArray(engine.sprites);

	engine.svi.updateScreen();
	engine.svi.drawScreen();


	//engine.svi.load("../Assets/Sound/b423b42.wav");
	//engine.svi.play();
	
	
	while (1)
	{
		engine.svi.input();
	}
	t1.join();
}





