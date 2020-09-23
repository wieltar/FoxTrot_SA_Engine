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
#include "SceneManager.h"

/// @brief 
class Engine
{
public:
	Engine();
	~Engine();

	void initScene();

	// TODO: Set to private after testing
	
//public:


	FileParser fileParser;
	PhysicsEngine physicsEngine;
	SVIEngine svi;
	ParticleEngine particleEngine;
	SceneManager sceneManager;

	void registerSceneManagerPointerWithSVIPointer();
	void loadSpriteArray(vector<Sprite> spriteVector);


	void TESTfillSpriteVector(); // TODO: remove after testing.
	vector<Sprite> sprites;

};




#endif