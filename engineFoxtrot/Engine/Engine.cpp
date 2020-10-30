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
		physicsEngine.registerObjectInCurrentVectorWithPhysicsEngine();
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// Creates a new Scene in the Scene manager given the sceneID
/// @param sceneID 
/// int SceneID
void Engine::createNewSceneWithSceneID(const int sceneID)
{
	try
	{
		sceneManager.createNewScene(sceneID);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// @param sceneID 
/// @param id 
/// @param xPos 
/// @param yPos 
/// @param height 
/// @param width 
/// @param stat 
void Engine::createNewObjectWithSceneID(const int sceneID, const int id, const int xPos, const int yPos, const int height, const int width, const bool stat)
{
	createNewObjectWithSceneID(sceneID,id,xPos,yPos,height,width,stat,0,0,0,0,0);
}

void Engine::pollEvents() {
	this->inputEngine.pollEvents();
}
/// @brief 
/// @param scene
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
/// @param spritesVector 
void Engine::loadSpriteArray(vector<SpriteObject> spritesVector)
{
	try
	{
		for (auto sprite : spritesVector) {
			videoEngine.loadImage(sprite);
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


/// @brief 
/// Load a animated sprite (PNG) into the AnimatedTexture map
/// @param spriteObject 
/// @param filename
void Engine::loadSprite(SpriteObject spriteObject) {
	struct stat buffer;
	bool exists = (stat(spriteObject.getfileName(), &buffer) == 0);
	if (!exists)
		throw ERROR_CODE_IMAGE_FILE_NOT_FOUND;
	if (spriteObject.getTextureID() == NULL) {
		throw ERROR_CODE_IMAGE_CANNOT_BE_SAVED;
	}
	videoEngine.loadImage(spriteObject);
}