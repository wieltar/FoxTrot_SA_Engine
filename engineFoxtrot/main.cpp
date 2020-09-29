#pragma once
#include <iostream>
#include "Engine.h"
#include <Windows.h>
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
	engine.svi.load("piano2.wav", "piano");
	engine.svi.load("organfinale.wav", "organ");
	engine.svi.unload("organ");
	engine.svi.play("piano");
	engine.svi.play("organ");
	while (true) {

	}
}





