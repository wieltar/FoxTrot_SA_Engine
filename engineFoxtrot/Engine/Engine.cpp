#include "stdafx.h"
#include "Engine.h"

/// @brief 
Engine::Engine()
{
	sviEngine.pointerToCurrentScene =	 &sceneManager.currentScene;
	physicsEngine.pointerToCurrentScene = &sceneManager.currentScene;

	eventManager.subscribe(EventType::ENGINE60, &sviEngine);
	//sviEngine.initSDL();
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
		sviEngine.loadImage(spriteID, assetPath);
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
			sviEngine.loadImage(sprite.spriteID, sprite.filename);
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
	while (!stopThreadTick60){
		//eventManager.notify(EventType::ENGINE60, new Object);

		this_thread::sleep_for(chrono::milliseconds(ENGINE_TICK60));
		eventManager.notify(EventType::ENGINE60, new Object(1));
		//svi.receiveTick();
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

		//eventManager.notify(EventType::ENGINE30, new Object);
		physicsEngine.update30();

	}
	cout << "Thread killed 30" << endl;
}

/// @brief 
/// Start the 2 threads. 
void Engine::startTickThreads()
{
	engineTick60Thread = new thread(&Engine::engineTick60, this);
	engineTick30Thread = new thread(&Engine::engineTick30, this);

	engineTick60Thread->detach();
	engineTick30Thread->detach();
}

/// @brief
/// Stop the 2 threads
void Engine::stopTickThreads()
{
	//engineTick60Thread->join();
	//engineTick30Thread->join();
	stopThreadTick60 = true;
	stopThreadTick30 = true;
}

/// @brief 
/// @param listener 
/// @param eventType 
void Engine::addEventListener(EventListener* listener, const EventType eventType) {
    eventManager.subscribe(eventType, listener);
}

