#pragma once
#include <iostream>
#include "Engine.h"

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/


Engine engine;

int main() {

	engine.svi.load("../Assets/Sound/b423b42.wav");
	engine.svi.play();
	
	while (1)
	{
		engine.svi.input();
	}
}




