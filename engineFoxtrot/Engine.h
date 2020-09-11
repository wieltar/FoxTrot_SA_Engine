#pragma once
#include <vector> 
#include "Scene.h"
#include "FileParser.h"
#include "UserInput.h"
#include "Sound.h"
#include "PhysicsEngine.h"
#include "Video.h"
#include "ParticleEngine.h"

class Engine
{
private:
	FileParser* fileParser;
	UserInput* userInput;
	Sound* sound;
	PhysicsEngine* physicsEngine;
	Video* video;
	ParticleEngine* particleEngine;

	std::vector<Component*> Components;
};

