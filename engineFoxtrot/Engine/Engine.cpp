#include "stdafx.h"
#include "Engine.h"
#include <Events\AppTickEvent30.h>
#include <Events\AppTickEvent60.h>

/// @brief 
Engine::Engine()
{
	videoEngine.pointerToCurrentScene =	 &sceneManager.currentScene;
	physicsEngine.pointerToCurrentScene = &sceneManager.currentScene;
	frameData = new FrameData;

	//this->startTickThreads();
}

/// @brief 
Engine::~Engine()
{
}

/// @brief 
/// Set the current Scene in the scenemanager. Called from game to switch screens.
/// @param sceneID 
/// SceneID to set the currentSceneID to
void Engine::setCurrentScene(const int sceneID)
{
	try
	{
		sceneManager.setCurrentScene(sceneID);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

void Engine::insertScene(Scene* scene)
{
	try
	{
		sceneManager.insertScene(scene);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// @param spriteID 
/// @param assetPath 
void Engine::linkSpriteIDWithAssetPath(const int spriteID, const char * assetPath)
 {
	try
	{
		videoEngine.loadImage(spriteID, assetPath);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// @param spritesVector 
void Engine::loadSpriteArray(vector<Sprite> spritesVector)
{
	try
	{
		for (auto sprite : spritesVector) {
			videoEngine.loadImage(sprite.spriteID, sprite.filename);
		}
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// Thread that gives a tick 60 times per second
void Engine::engineTick60()
{
	cout << "Thread started" << endl;
	pollInput();
	while (!stopThreadTick60){
		frameData->startTimer();
		this_thread::sleep_for(chrono::milliseconds(ENGINE_TICK60));		
		AppTickEvent60 appTick;
		EventSingleton::get_instance().dispatchEvent<AppTickEvent60>(appTick);
		FrameData::gameFps = frameData->calculateAverageFps();
	}

	cout << "Thread killed 60" << endl;
}

/// @brief 
/// Thread that gives a tick 30 times per second
void Engine::engineTick30()
{
	cout << "Thread started" << endl;
	while (!stopThreadTick30) {
		this_thread::sleep_for(chrono::milliseconds(ENGINE_TICK30));
		AppTickEvent30 appTick;
		EventSingleton::get_instance().dispatchEvent<AppTickEvent30>(appTick);
	}
	cout << "Thread killed 30" << endl;
}

/// @brief 
/// Start the 2 threads. 
void Engine::startTickThreads()
{
	/*engineTick60Thread = new thread(&Engine::engineTick60, this);
	engineTick60Thread->detach();*/

	/*engineTick30Thread = new thread(&Engine::engineTick30, this);
	engineTick30Thread->detach();*/
}

/// @brief
/// Stop the 2 threads
void Engine::stopTickThreads()
{
	//engineTick60Thread->join();
	//stopThreadTick60 = true;

	engineTick30Thread->join();
	stopThreadTick30 = true;
}

/// @brief 
/// Polls for input using SDL poll events
void Engine::pollInput()
{
	inputEngine.updateInput();
}

/// @brief 
/// Function to bind keys to commands.
/// @param key KeyCode key
/// @param command Command to be executed
void Engine::configureInput(KeyCode key, Command* command)
{
	inputEngine.configure(key, command);
}

