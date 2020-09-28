#include "SceneManager.h"

/// @brief Constructor
SceneManager::SceneManager()
{

}

/// @brief Destructor
SceneManager::~SceneManager()
{
}

/// @brief 
/// @param ObjectID 
/// @param X 
/// @param Y 
void SceneManager::moveObject(int ObjectID, int X, int Y)
{
	if (!currentScene) throw ERROR_CODE_TRYING_TO_RUN_COMMAND_ON_UNKNOWN_OBJECT;
	currentScene->getObject(ObjectID)->setPositionX(X);
	currentScene->getObject(ObjectID)->setPositionY(Y);
}

void SceneManager::moveObjectRelative(int ObjectID, int moveXby, int moveYby)
{
	if (!currentScene) throw ERROR_CODE_TRYING_TO_RUN_COMMAND_ON_UNKNOWN_OBJECT;
	currentScene->getObject(ObjectID)->setPositionX(currentScene->getObject(ObjectID)->getPositionX() + moveXby);
	currentScene->getObject(ObjectID)->setPositionX(currentScene->getObject(ObjectID)->getPositionY() + moveYby);
}

Scene* SceneManager::getSceneWithSceneID(int sceneID)
{
	for (Scene* s : scenes)
	{
		if (s->sceneID == sceneID) return s;
	}
}


void SceneManager::createNewScene(int sceneID)
{
	scenes.push_back(new Scene(sceneID));
}

void SceneManager::setCurrentScene(int sceneID)
{
	if (scenes.empty()) throw ERROR_CODE_SETTING_CURRENTSCENE_WHEN_SCENES_IS_EMPTY;

	currentScene = findSceneWithID(sceneID);
	pointerToCurrentObjectVector = currentScene->objects;
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
