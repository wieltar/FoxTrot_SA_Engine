
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

	void receiveTick();

	void setCurrentScene(int sceneID);
	void createNewSceneWithSceneID(int sceneID);
	void createNewObjectWithSceneID(int sceneID, int id, int xPos, int yPos, int height, int width);
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

private:

	FileParser fileParser;
	PhysicsEngine physicsEngine;
	SVIEngine svi;
	ParticleEngine particleEngine;
	SceneManager sceneManager;

	void loadSpriteArray(vector<Sprite> spriteVector);
};




#endif