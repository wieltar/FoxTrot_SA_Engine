#pragma once

#ifndef ENGINE__H
#define ENGINE__H

#include "./SceneManager/SceneManager.h"
#include "./FileParser/FileParser.h"
#include "./Physics/PhysicsEngine.h"
#include "./ParticleSystem/ParticleEngine.h"
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
class Engine
{
public:
	API Engine();
	API ~Engine();

//private:
	API void engineTick60();
	API void engineTick30();
	API void startTickThreads();
	API void stopTickThreads();

	atomic_bool stopThreadTick60 = false;
	atomic_bool stopThreadTick30 = false;

	thread *engineTick60Thread = nullptr;
	thread *engineTick30Thread = nullptr;

	//SceneManager calls
	API void setCurrentScene(const int sceneID);
	API void insertScene(Scene * scene);

	// Video calls
	API void linkSpriteIDWithAssetPath(const int spriteID, const char* assetPath);

	API void pollInput();
	API void configureInput(KeyCode key, Command* command, bool runOnce = false);

	/// @brief
	/// Generic function for creating command externally
	template <class T>
	T* makeCommand() {
		static_assert(is_base_of<Command, T>::value, "Type parameter for this function must derive from Command");
		return inputEngine.makeCommand<T>();
	}

	//TODO make private
private:
	PhysicsEngine physicsEngine;
	VideoEngine videoEngine;
private:
	ParticleEngine particleEngine;
	SoundEngine soundEngine;
	InputEngine inputEngine;
	FileParser fileParser;
	SceneManager sceneManager;

	FrameData* frameData = nullptr;

	void loadSpriteArray(vector<Sprite> spriteVector);
};
#endif
