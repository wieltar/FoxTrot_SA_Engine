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
/// A function to check if a scene exists
/// @param sceneID 
/// Identifier to a SceneID. 
/// @return 
/// If SceneID has a valid scene returns true else false
bool SceneManager::checkIfSceneExists(const int sceneID)
{
	for (Scene* s : scenes)
	{
		if (s->getSceneID() == sceneID) return true;
	}
	return false;
}

/// @brief 
/// A function to create a new scene, if a scene already exists throw ERROR_CODE_SCENEMANAGER_SCENE_ALREADY_EXISTS
/// @param sceneID 
/// Identifier to a SceneID.
void SceneManager::createNewScene(const int sceneID)
{
	cout << "Trying to create scene with id: " << sceneID << endl;
	if (checkIfSceneExists(sceneID))
	{
		throw ERROR_CODE_SCENEMANAGER_SCENE_ALREADY_EXISTS;
	}
	scenes.push_back(new Scene(sceneID));
}

/// @brief 
/// A function to change a scene
/// If a scene does not exists throw ERROR_CODE_SCENEMANAGER_SCENES_IS_EMPTY
/// @param sceneID 
/// Identifier to a SceneID.
void SceneManager::setCurrentScene(const int sceneID)
{
	if (scenes.empty()) throw ERROR_CODE_SCENEMANAGER_SCENES_IS_EMPTY;

	currentScene = getSceneWithID(sceneID);
	pointerToCurrentObjectVector = currentScene->getPtrToObjects();
	cout << "Setting current scene to " << sceneID << " with amount of obj: " << currentScene->getPtrToObjects().size() << endl;
}

/// @brief 
/// Get a scene with a sceneID
/// If a scene does not exists throw ERROR_CODE_SCENEMANAGER_SCENES_IS_EMPTY
/// @param sceneID 
/// Identifier to a SceneID.
/// @return
/// Returns pointer to the found Scene. 
Scene* SceneManager::getSceneWithID(const int sceneID)
{
	if (scenes.empty()) throw ERROR_CODE_SCENEMANAGER_SCENES_IS_EMPTY;
	for (Scene * s : scenes)
	{
		if (s->getSceneID() == sceneID)
		{
			return s;
		}
	}
	throw ERROR_CODE_SCENEMANAGER_CANT_FIND_SCENE_WITH_ID;
}
