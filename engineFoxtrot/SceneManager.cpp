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
	if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
	currentScene->getObject(ObjectID)->setPositionX(X);
	currentScene->getObject(ObjectID)->setPositionY(Y);
}

/// @brief 
/// @param ObjectID 
/// @param moveXby 
/// @param moveYby 
void SceneManager::moveObjectRelative(int ObjectID, int moveXby, int moveYby)
{
	if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
	currentScene->getObject(ObjectID)->setPositionX(currentScene->getObject(ObjectID)->getPositionX() + moveXby);
	currentScene->getObject(ObjectID)->setPositionX(currentScene->getObject(ObjectID)->getPositionY() + moveYby);
}

/// @brief 
/// @param sceneID 
/// @return 
bool SceneManager::checkIfSceneExists(int sceneID)
{
	for (Scene* s : scenes)
	{
		if (s->getSceneID() == sceneID) return true;
	}
	return false;
}

/// @brief 
/// @param sceneID 
void SceneManager::createNewScene(int sceneID)
{
	if (checkIfSceneExists(sceneID)) throw ERROR_CODE_SCENEMANAGER_SCENE_ALREADY_EXISTS;
	scenes.push_back(new Scene(sceneID));
}

/// @brief 
/// @param sceneID 
void SceneManager::setCurrentScene(int sceneID)
{
	if (scenes.empty()) throw ERROR_CODE_SCENEMANAGER_SCENES_IS_EMPTY;

	currentScene = getSceneWithID(sceneID);
	pointerToCurrentObjectVector = currentScene->getPtrToObjects();
}

/// @brief 
/// @param sceneID 
/// @return 
Scene* SceneManager::getSceneWithID(int sceneID)
{
	if (scenes.empty()) throw ERROR_CODE_SCENEMANAGER_SCENES_IS_EMPTY;
	for (auto s : scenes)
	{
		if (s->getSceneID() == sceneID)
		{
			return s;
		}
	}
	throw ERROR_CODE_SCENEMANAGER_CANT_FIND_SCENE_WITH_ID;
}
