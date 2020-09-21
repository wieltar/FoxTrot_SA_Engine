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
#include "PhysicsEngine.h"
#include "SVIEngine.h"
#include "ParticleEngine.h"

/// @brief 
class Engine
{
public:
	Engine();
	~Engine();

	// Set to private after testing
public:


	FileParser fileParser;
	PhysicsEngine physicsEngine;
	SVIEngine svi;
	ParticleEngine particleEngine;
};




#endif