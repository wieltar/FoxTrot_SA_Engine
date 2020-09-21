#pragma once
#include "Scene.h"

#include <iostream>

using namespace std;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void moveObject(int ObjectID, int X, int Y);
	void moveObjectRelative(int ObjectID, int moveXby, int moveYby);

	void setCurrentScene(int sceneID);

private:

	vector<Scene*> Scenes;
	
	Scene* currentScene;
};


