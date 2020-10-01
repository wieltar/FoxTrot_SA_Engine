#include "Engine.h"

/// @brief 
Engine::Engine()
{
	svi.pointerToObjectVector = &sceneManager.pointerToCurrentObjectVector;
	svi = SVIEngine::SVIEngine(eventManager);

	eventManager.subscribe(EventType::ENGINE60, &svi);
}

/// @brief 
Engine::~Engine()
{
}

/// @brief 
/// Set the current Scene in the scenemanager. Called from game to switch screens.
/// @param sceneID 
/// SceneID to set the currentSceneID to
void Engine::setCurrentScene(int sceneID)
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
void Engine::createNewSceneWithSceneID(int sceneID)
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
void Engine::createNewObjectWithSceneID(int sceneID, int id, int xPos, int yPos, int height, int width)
{
	try
	{
		sceneManager.getSceneWithID(sceneID)->addNewObject(id, xPos, yPos, height, width);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// @param spriteID 
/// @param assetPath 
void Engine::linkSpriteIDWithAssetPath(int spriteID, const char * assetPath)
 {
	try
	{
	svi.loadImage(spriteID, assetPath);
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
	cout << spritesVector.size() << endl; // TODO REMOVE
	for (auto sprite : spritesVector) {
		cout << sprite.spriteID << "," << sprite.filename << endl;
		svi.loadImage(sprite.spriteID, sprite.filename);
	}
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
void Engine::receiveTick()
{
	// Todo
	// Maybe position doesnt need to update every 60s?
	//svi.receiveTick();
}











void Engine::engineTick60()
{
	cout << "Thread started" << endl;
	while (!stopThreadTick60){
		//eventManager.notify(EventType::ENGINE60, new Object);

		this_thread::sleep_for(chrono::milliseconds(17));
		eventManager.notify(EventType::ENGINE60, new Object);
		//svi.receiveTick();
	}

	cout << "Thread killed 60" << endl;
}

void Engine::engineTick30()
{
	cout << "Thread started" << endl;
	while (!stopThreadTick30) {
		this_thread::sleep_for(chrono::milliseconds(33));

		//eventManager.notify(EventType::ENGINE30, new Object);

	}
	cout << "Thread killed 30" << endl;
}

void Engine::startTickThreads()
{
	engineTick60Thread = new thread(&Engine::engineTick60, this);
	engineTick30Thread = new thread(&Engine::engineTick30, this);

	engineTick60Thread->detach();
	engineTick30Thread->detach();
}

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
void Engine::addEventListener(EventListener* listener, EventType eventType) {
    eventManager.subscribe(eventType, listener);
}

