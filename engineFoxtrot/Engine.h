
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
#include "EventManager.h"
#include "EventListener.h"


/// @brief 
class Engine
{
public:
	Engine();
	~Engine();

	void initScene();

	void receiveTick();

	// TODO: Set to private after testing
	
//public:

	EventManager eventManager;

	FileParser fileParser;
	PhysicsEngine physicsEngine;
	SVIEngine svi;
	ParticleEngine particleEngine;
	SceneManager sceneManager;

	void registerSceneManagerPointerWithSVIPointer();
	void loadSpriteArray(vector<Sprite> spriteVector);


	void TESTfillSpriteVector(); // TODO: remove after testing.
	vector<Sprite> sprites;


	void addEventListener(EventListener* listener, EventType eventType);
};




#endif