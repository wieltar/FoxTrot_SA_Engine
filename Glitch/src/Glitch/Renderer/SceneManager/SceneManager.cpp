#include "SceneManager.h"

namespace Glitch {
	/// @brief Constructor
	SceneManager::SceneManager()
	{

	}

	/// @brief Destructor
	SceneManager::~SceneManager()
	{
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

}