#include "Engine.h"


Engine::Engine()
{
	svi.pointerToObjectVector = &sceneManager.pointerToCurrentObjectVector;
}

Engine::~Engine()
{
}

void Engine::setCurrentScene(int sceneID)
{
	sceneManager.setCurrentScene(sceneID);
}

void Engine::createNewSceneWithSceneID(int sceneID)
{
	sceneManager.createNewScene(sceneID);
}

void Engine::createNewObjectWithSceneID(int sceneID, int id, int xPos, int yPos, int height, int width)
{
	sceneManager.getSceneWithSceneID(sceneID)->addNewObject(id, xPos, yPos, height, width);
}

void Engine::linkSpriteIDWithAssetPath(int spriteID, const char * assetPath)
{
	svi.loadImage(spriteID, assetPath);
}

void Engine::loadSpriteArray(vector<Sprite> spritesVector)
{
	cout << spritesVector.size() << endl;
	for (auto sprite : spritesVector) {
		cout << sprite.spriteID << "," << sprite.filename << endl;
		svi.loadImage(sprite.spriteID, sprite.filename);
	}
}
void Engine::receiveTick()
{
	// Todo
	// Maybe position doesnt need to update every 60s?
	svi.receiveTick();
	svi.clearScreen();
	svi.updateScreen();
	svi.drawScreen();
}

void Engine::addEventListener(EventListener* listener, EventType eventType) {
    eventManager.subscribe(eventType, listener);
}

