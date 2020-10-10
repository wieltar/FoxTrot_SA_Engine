#include "Engine.h"

/// @brief 
Engine::Engine()
{
	sviEngine.pointerToObjectVector = &sceneManager.pointerToCurrentObjectVector;
	physicsEngine.pointerToObjectVector = &sceneManager.pointerToCurrentObjectVector;

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

/// @brief 
/// @param sceneID 
/// @param id 
/// @param xPos 
/// @param yPos 
/// @param height 
/// @param width 
void Engine::createNewObjectWithSceneID(const int sceneID, const int id, const int xPos, const int yPos, const int height, const int width, const bool stat, const int speed, const int jumpHeight, const int density, const int friction, const int restitution)
{
	try
	{
		cout << "creating new obj sceneID: " << sceneID << endl;
		sceneManager.getSceneWithID(sceneID)->addNewObject(id, xPos, yPos, height, width,speed,jumpHeight, density, friction,restitution, stat);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// @param sceneID 
/// @param object 
void Engine::createObject(const int sceneID, Object* object) {
	try
	{
		cout << "creating new obj sceneID: " << sceneID << endl;
		sceneManager.getSceneWithID(sceneID)->addNewObject(object);
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

