#pragma once

#ifndef ENGINE__H
#define ENGINE__H

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

#include <vector> 
#include <iostream>
#include <math.h>

#include "Scene.h"
#include "FileParser.h"
#include "UserInput.h"
#include "Sound.h"
#include "PhysicsEngine.h"
#include "Video.h"
#include "ParticleEngine.h"

class Engine
{
public:



private:
	FileParser* fileParser;
	UserInput* userInput;
	Sound* sound;
	PhysicsEngine* physicsEngine;
	Video* video;
	ParticleEngine* particleEngine;

	std::vector<Component*> Components;
};



#endif