#pragma once

#ifndef ENGINE__H
#define ENGINE__H

#include "./SceneManager/SceneManager.h"
#include "./FileParser/FileParser.h"
#include "./Physics/PhysicsEngine.h"
#include "./SVI(Temp)/SVIEngine.h"
#include "./Particles/ParticleEngine.h"
#include "./SceneManager/SceneManager.h"
#include "./Events/EventManager.h"
#include "./Events/EventListener.h"

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

	void addEventListener(EventListener* listener, const EventType eventType);

	void loadSprite(int spriteID, const char* filename, int singleSpriteHeight, int singleSpriteWidth, int size);


	EventManager eventManager;
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
