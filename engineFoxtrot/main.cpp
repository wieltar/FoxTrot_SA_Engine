#pragma once
#include <iostream>
#include "Engine.h"

#include "box2d/box2d.h"
using namespace std;

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

// TODO : Set object folder up with interface route

Engine engine;

int main() {

	Engine* engine{ new Engine };
	engine->addEventListener(new PhysicsEngine, EventType::MOVE);
	engine->eventManager.notify(EventType::MOVE, new Object);

	engine->svi.load("BGM.wav", "piano");
	engine->svi.play("piano");

	while (1) {
		
	}
	return 0;
}


