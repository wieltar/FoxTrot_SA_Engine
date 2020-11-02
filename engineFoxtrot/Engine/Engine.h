#pragma once

#ifndef ENGINE__H
#define ENGINE__H

#include "./SceneManager/SceneManager.h"
#include "./FileParser/FileParser.h"
#include "./Physics/PhysicsEngine.h"
#include "./Particles/ParticleEngine.h"
#include "./SceneManager/SceneManager.h"

#include "Events/EventSingleton.h"
#include "./Video/VideoEngine.h"
#include "./Sound/SoundEngine.h"
#include "./Input/InputEngine.h"
#include "./Fps/FrameData.h"

// TODO Weet niet of deze hier moet?!?!??! Is even voor de test
#include "Events/Codes/KeyCodes.h"

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

//private:
	void engineTick60();
	void engineTick30();
	void startTickThreads();
	void stopTickThreads();

	atomic_bool stopThreadTick60 = false;
	atomic_bool stopThreadTick30 = false;

	thread *engineTick60Thread = nullptr;
	thread *engineTick30Thread = nullptr;

	//SceneManager calls
	void setCurrentScene(const int sceneID);
	void insertScene(Scene * scene);

	// Video calls
	void loadSprite(SpriteObject* spriteObject);

	//Input calls
	void pollInput();
	void configureInput(KeyCode key, Command* command);

	void pollEvents();

	PhysicsEngine physicsEngine;
private:
	SoundEngine soundEngine;
	InputEngine inputEngine;
	FileParser fileParser;
	ParticleEngine particleEngine;
	SceneManager sceneManager;
	VideoEngine videoEngine;

	FrameData* frameData = nullptr;

	void loadSpriteArray(vector<SpriteObject> spriteVector);
};
#endif
