#include "Engine.h"

/// @brief 
Engine::Engine()
{
	svi.pointerToObjectVector = &sceneManager.pointerToCurrentObjectVector;
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
	svi.loadImage(spriteID, assetPath);
}

/// @brief 
/// @param spritesVector 
void Engine::loadSpriteArray(vector<Sprite> spritesVector)
{
	cout << spritesVector.size() << endl;
	for (auto sprite : spritesVector) {
		cout << sprite.spriteID << "," << sprite.filename << endl;
		svi.loadImage(sprite.spriteID, sprite.filename);
	}
}

/// @brief 
void Engine::receiveTick()
{
	// Todo
	// Maybe position doesnt need to update every 60s?
	svi.receiveTick();
	svi.clearScreen();
	svi.updateScreen();
	svi.drawScreen();
}

/// @brief 
/// @param listener 
/// @param eventType 
void Engine::addEventListener(EventListener* listener, EventType eventType) {
    eventManager.subscribe(eventType, listener);
}

