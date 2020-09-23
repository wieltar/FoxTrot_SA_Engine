#pragma once
#include <iostream>
#include "Engine.h"
#include "Scene.h"

using namespace std;

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

// TODO : Set object folder up with interface route

Engine engine;

int main() {
	
	
	engine.initScene();
	Scene scene;
	Object object;

	engine.sceneManager.scenes.push_back(&scene);

	scene.sceneID = 10;

	scene.Objects.push_back(&object);
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
	engine.svi.loadImage(1, "../Assets/Sprites/Simple.png");
	engine.svi.loadImage(2, "../Assets/Sprites/Simple.png");
	engine.svi.loadImage(3, "../Assets/Sprites/Simple.png");
	engine.svi.renderCopy(1, 10, 10, 100, 100);
	engine.svi.renderCopy(2, 110, 10, 100, 100);
	engine.svi.renderCopy(3, 10, 110, 100, 100);
	engine.svi.updateScreen();


	//engine.svi.load("../Assets/Sound/b423b42.wav");
	//engine.svi.play();
	
	
	while (1)
	{
		engine.svi.input();
	}
}





