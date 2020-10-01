#pragma once
#include <iostream>
#include "Engine.h"

#include "box2d/box2d.h"
#include "SoundManager.h"
#include "Windows.h"
using namespace std;

// Doxygen
// Cntrl + / above function or class to generate Doxygen
// https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/
// Installing
// https://computingonplains.wordpress.com/doxygen-and-visual-studio/

// TODO : Set object folder up with interface route

Engine engine;

int main() {

	SoundManager soundManager;

	soundManager.AddFile("bgm", "BGM.wav");
	soundManager.PlayMusic("bgm", 20);
	while (1) {
		
	}
	return 0;
}