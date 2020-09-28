#pragma once
#include "Scene.h"

#include <iostream>
#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

using namespace std;

/// @brief 
/// Contains all scenes. Manages all scenes and objects. All calls from engine containing object movements should be handled in the scene manager. 
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void moveObject(int ObjectID, int X, int Y);
	void moveObjectRelative(int ObjectID, int moveXby, int moveYby);

	void createNewScene(int sceneID);
	void setCurrentScene(int sceneID);

	Scene* getSceneWithSceneID(int);

	vector <Object*> pointerToCurrentObjectVector;

private:

	Scene* findSceneWithID(int sceneID);

	vector<Scene*> scenes;
	Scene* currentScene;

};


