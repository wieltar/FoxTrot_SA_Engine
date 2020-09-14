#pragma once
#include <iostream>
#include "Engine.h"

#include "../box2d-master/include/box2d/box2d.h"
using namespace std;
// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

// TODO : Set object folder up with interface route

Engine engine;

int main() {

	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);

	cout << "Hello world!" << endl;
	return 0;
	//engine.svi.load("../Assets/Sound/b423b42.wav");
	//engine.svi.play();
	//engine.svi.testLoopVideo();
	//
	//while (1)
	//{
	//	engine.svi.input();
	//}
}




