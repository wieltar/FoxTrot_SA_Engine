#include "glpch.h"
#include "SceneManager.h"
namespace Glitch {
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
	/// @param ObjectID 
	/// @param rotation 
	void SceneManager::rotateObject(int ObjectID, int rotation)
	{
		if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
		currentScene->getObject(ObjectID)->setRotation(rotation);
	}

	/// @brief 
	/// @param ObjectID 
	/// @param scale 
	void SceneManager::setObjectScale(int ObjectID, int scale)
	{
		if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
		currentScene->getObject(ObjectID)->setScale(scale);
	}

	/// @brief 
	/// @param ObjectID 
	/// @param dir 
	void SceneManager::setObjectDirection(int ObjectID, int dir)
	{
		if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
		currentScene->getObject(ObjectID)->setDirection(dir);
	}

	/// @brief 
	/// @param ObjectID 
	/// @param stat 
	void SceneManager::setObjectStatic(int ObjectID, bool stat)
	{
		if (!currentScene) throw ERROR_CODE_SCENEMANAGER_NO_CURRENT_SCENE;
		currentScene->getObject(ObjectID)->setStatic(stat);
	}
}