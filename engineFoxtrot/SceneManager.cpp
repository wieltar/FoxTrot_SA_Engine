#include "SceneManager.h"

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{
}

void SceneManager::moveObject(int ObjectID, int X, int Y)
{

}

void SceneManager::moveObjectRelative(int ObjectID, int moveXby, int moveYby)
{
}

void SceneManager::receiveTick()
{

}

void SceneManager::setCurrentScene(int sceneID)
{
	if (scenes.empty()) throw ERROR_CODE_SETTING_CURRENTSCENE_WHEN_SCENES_IS_EMPTY;

	currentScene = findSceneWithID(sceneID);
	pointerToCurrentObjectVector = currentScene->Objects;
}

Scene* SceneManager::findSceneWithID(int sceneID)
{
	if (scenes.empty()) throw ERROR_CODE_SETTING_CURRENTSCENE_WHEN_SCENES_IS_EMPTY;
	for (auto s : scenes)
	{
		if (s->sceneID == sceneID)
		{
			return s;
		}
	}
	throw ERROR_CODE_SEARCHING_FOR_UNKNOWN_SCENE_ID;
}
