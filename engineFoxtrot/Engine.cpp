#include "Engine.h"


Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::initScene()
{
	// TODO: Set object list to other object list
	registerSceneManagerPointerWithSVIPointer();
}

void Engine::registerSceneManagerPointerWithSVIPointer()
{
	svi.pointerToObjectVector = &sceneManager.pointerToCurrentObjectVector;
}

void Engine::receiveTick()
{
	// Todo
	// Maybe position doesnt need to update every 60s?
	sceneManager.receiveTick();
	svi.receiveTick();

}