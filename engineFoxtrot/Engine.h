
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

	void setCurrentScene(const int sceneID);
	void createNewSceneWithSceneID(const int sceneID);

	void createObject(const int sceneID, Object* object);
	void createNewObjectWithSceneID(const int sceneID, const int id, const int xPos, const int yPos, const int height, const int width, const bool stat);
	void createNewObjectWithSceneID(const int sceneID, const int id, const int xPos, const int yPos, const int height, const int width, const bool stat, const int speed, const int jumpHeight, const int density, const int friction, const int restitution);
	void linkSpriteIDWithAssetPath(const int spriteID, const char* assetPath);

	void addEventListener(EventListener* listener, const EventType eventType);
	EventManager eventManager;

	// Object Modifiers
	void moveObjectTo(const int objId, const int x, const int y);
	void moveObjectBy(const int objId, const int withX, const int withY);
	void setObjectRotation(const int objId, const int rotation);
	void setObjectScale(const int objId, const int scale);
	void setObjectDirection(const int objId, const int dir);
	void setObjectStatic(const int objId, const bool stat);


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
