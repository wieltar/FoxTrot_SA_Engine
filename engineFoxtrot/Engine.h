
#pragma once

#ifndef ENGINE__H
#define ENGINE__H

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralDefines.h"
#include "GeneralHelperFunctions.cpp"

#include <vector> 
#include <iostream>
#include <math.h>
#include <thread>
#include <assert.h>
#include <chrono>
#include <future>

#include "Scene.h"
#include "FileParser.h"
#include "PhysicsEngine.h"
#include "SVIEngine.h"
#include "ParticleEngine.h"
#include "SceneManager.h"
#include "EventManager.h"
#include "EventListener.h"

#define	ENGINE_TICK60	 17
#define ENGINE_TICK30	 33

/// @brief 
#if(EXPORT)
class DLLEXPORT Engine
#else
class Engine
#endif
{
public:
	Engine();
	~Engine();

	// TODO: Set to private after testing
	
//private:
	void engineTick60();
	void engineTick30();
	void startTickThreads();
	void stopTickThreads();

	atomic_bool stopThreadTick60 = false;
	atomic_bool stopThreadTick30 = false;

	thread *engineTick60Thread = nullptr;
	thread *engineTick30Thread = nullptr;

	void setCurrentScene(int sceneID);
	void createNewSceneWithSceneID(int sceneID);

	void createObject(int sceneID, Object* object);
	void createNewObjectWithSceneID(int sceneID, int id, int xPos, int yPos, int height, int width, bool stat);
	void createNewObjectWithSceneID(int sceneID, int id, int xPos, int yPos, int height, int width, bool stat, int speed, int jumpHeight, int density, int friction, int restitution);
	void linkSpriteIDWithAssetPath(int spriteID, const char* assetPath);

	void addEventListener(EventListener* listener, EventType eventType);
	EventManager eventManager;

	// Object Modifiers
	void moveObjectTo(int objId, int x, int y);
	void moveObjectBy(int objId, int withX, int withY);
	void setObjectRotation(int objId, int rotation);
	void setObjectScale(int objId, int scale);
	void setObjectDirection(int objId, int dir);
	void setObjectStatic(int objId, bool stat);


	//TODO make private

	PhysicsEngine physicsEngine;
private:

	SVIEngine sviEngine;
	FileParser fileParser;
	ParticleEngine particleEngine;
	SceneManager sceneManager;

	void loadSpriteArray(vector<Sprite> spriteVector);
};

#endif
