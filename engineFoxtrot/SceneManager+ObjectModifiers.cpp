#include "SceneManager.h"

/// @brief 
/// Ability to move an object in the currentScene. 
/// Throws error if no current scene is selected or objectID does not exist in currentScene
/// @param ObjectID 
/// Identifier to a ObjectID.
/// @param X 
/// Object new X location
/// @param Y 
/// Object new Y location
void SceneManager::moveObject(const int ObjectID, const int X, const int Y)
{
	if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
	if (!currentScene->checkIfObjectExists(ObjectID))ERROR_CODE_SCENEMANAGER_OBJECTID_DOES_NOT_EXIST_IN_CURRENT_SCENE;
	currentScene->getObject(ObjectID)->setPositionX(X);
	currentScene->getObject(ObjectID)->setPositionY(Y);
}

/// @brief 
/// A function to move a object relative to its position
/// Throws error if no current scene is selected or objectID does not exist in currentScene
/// @param ObjectID 
/// Identifier to a ObjectID.
/// @param moveXby 
/// New Object Location will increase by moveXBy.
/// Pseudo:
/// New Object Location = CurrentObjectLocationX + moveXby;
/// @param moveYby 
/// New Object Location will increase by moveYBy.
/// Pseudo:
/// New Object Location = CurrentObjectLocationY + moveYby;
void SceneManager::moveObjectRelative(const int ObjectID, const int moveXby, const int moveYby)
{
	if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
	if (!currentScene->checkIfObjectExists(ObjectID))ERROR_CODE_SCENEMANAGER_OBJECTID_DOES_NOT_EXIST_IN_CURRENT_SCENE;
	currentScene->getObject(ObjectID)->setPositionX(currentScene->getObject(ObjectID)->getPositionX() + moveXby);
	currentScene->getObject(ObjectID)->setPositionX(currentScene->getObject(ObjectID)->getPositionY() + moveYby);
}

/// @brief 
/// Rotates the selected Object
/// Throws error if no current scene is selected or objectID does not exist in currentScene
/// @param ObjectID 
/// Identifier to a ObjectID.
/// @param rotation 
/// Rotation to rotate the object to
void SceneManager::rotateObject(const int ObjectID, const int rotation)
{
	if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
	if (!currentScene->checkIfObjectExists(ObjectID))ERROR_CODE_SCENEMANAGER_OBJECTID_DOES_NOT_EXIST_IN_CURRENT_SCENE;
	currentScene->getObject(ObjectID)->setRotation(rotation);
}

/// @brief 
/// a function to change the scale off the object
/// Throws error if no current scene is selected or objectID does not exist in currentScene
/// @param ObjectID 
/// Identifier to a ObjectID.
/// @param scale 
/// New Object scale
void SceneManager::setObjectScale(const int ObjectID, const int scale)
{
	//TODO do we have to change the height/width
	if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
	if (!currentScene->checkIfObjectExists(ObjectID))ERROR_CODE_SCENEMANAGER_OBJECTID_DOES_NOT_EXIST_IN_CURRENT_SCENE;
	currentScene->getObject(ObjectID)->setScale(scale);
}

/// @brief 
/// Set the object direction
/// Throws error if no current scene is selected or objectID does not exist in currentScene
/// @param ObjectID 
/// Identifier to a ObjectID.
/// @param dir
/// New direction the the selected object
void SceneManager::setObjectDirection(const int ObjectID, const int dir)
{
	if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
	if (!currentScene->checkIfObjectExists(ObjectID))ERROR_CODE_SCENEMANAGER_OBJECTID_DOES_NOT_EXIST_IN_CURRENT_SCENE;
	currentScene->getObject(ObjectID)->setDirection(dir);
}

/// @brief 
/// Change the object from static to dynamic
/// Throws error if no current scene is selected or objectID does not exist in currentScene
/// @param ObjectID 
/// Identifier to a ObjectID.
/// @param stat 
/// True for Static, false for Dynamic
void SceneManager::setObjectStatic(const int ObjectID, const bool stat)
{
	//TODO is this possible this because of different register object in physics
	if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
	if (!currentScene->checkIfObjectExists(ObjectID))ERROR_CODE_SCENEMANAGER_OBJECTID_DOES_NOT_EXIST_IN_CURRENT_SCENE;
	currentScene->getObject(ObjectID)->setStatic(stat);
}