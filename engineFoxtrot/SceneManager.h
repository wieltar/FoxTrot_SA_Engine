#pragma once
#include "Scene.h"

#include <iostream>
#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

using namespace std;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void moveObject(int ObjectID, int X, int Y);
	void moveObjectRelative(int ObjectID, int moveXby, int moveYby);

	void createNewScene(int sceneID);
	void setCurrentScene(int sceneID);

	void receiveTick();

	//Todo
	// Set private
public:
//private:

	Scene* findSceneWithID(int sceneID);

	vector<Scene*> scenes;

	vector <Object*> pointerToCurrentObjectVector;
	
	Scene* currentScene;

};


