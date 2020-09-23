#pragma once
#include <iostream>
#include "Engine.h"

using namespace std;

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

// TODO : Set object folder up with interface route

Engine engine;

int main() {

	//engine.svi.testLoopVideo(10,10);
	engine.svi.clearScreen();
	engine.svi.loadImage(1, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-run-00.png");
	engine.svi.loadImage(2, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-00.png");
	engine.svi.loadImage(3, "../Assets/Sprites/Project assets/Adventurer-1.5/Individual Sprites/adventurer-air-attack1-01.png");
	engine.svi.renderCopy(1, 10, 10, 100, 100);
	engine.svi.renderCopy(2, 110, 10, 100, 100);
	engine.svi.renderCopy(3, 10, 110, 100, 100);
	engine.svi.drawScreen();


	//engine.svi.load("../Assets/Sound/b423b42.wav");
	//engine.svi.play();
	
	
	while (1)
	{
		engine.svi.input();
	}
}





