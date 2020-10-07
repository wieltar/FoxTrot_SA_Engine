#include "SceneManager.h"

/// @brief 
/// @param ObjectID 
/// @param X 
/// @param Y 
/// a function to move a object static
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
/// a function to move a object relative
void SceneManager::moveObjectRelative(int ObjectID, int moveXby, int moveYby)
{
	if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
	currentScene->getObject(ObjectID)->setPositionX(currentScene->getObject(ObjectID)->getPositionX() + moveXby);
	currentScene->getObject(ObjectID)->setPositionX(currentScene->getObject(ObjectID)->getPositionY() + moveYby);
}

/// @brief 
/// @param ObjectID 
/// @param rotation 
/// a function to change the rotation off the object
void SceneManager::rotateObject(int ObjectID, int rotation)
{
	if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
	currentScene->getObject(ObjectID)->setRotation(rotation);
}

/// @brief 
/// @param ObjectID 
/// @param scale 
/// a function to change the direction off the object
void SceneManager::setObjectScale(int ObjectID, int scale)
{
	//TODO do we have to change the height/width
	if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
	currentScene->getObject(ObjectID)->setScale(scale);
}

/// @brief 
/// @param ObjectID 
/// @param dir 
/// a function to change the direction off the object
void SceneManager::setObjectDirection(int ObjectID, int dir)
{
	if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
	currentScene->getObject(ObjectID)->setDirection(dir);
}

/// @brief 
/// @param ObjectID 
/// @param stat 
/// a function to change the static value off the object
void SceneManager::setObjectStatic(int ObjectID, bool stat)
{
	//TODO is this possible this because of different register object in physics
	if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
	currentScene->getObject(ObjectID)->setStatic(stat);
}