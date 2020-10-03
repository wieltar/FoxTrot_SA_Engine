#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include "Object.h"
#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

using namespace std;

#include <vector>
#include "Object.h"

/// @brief 
/// Scene Class
/// Contains all the objects that should be drawn in this scene.

#if(EXPORT)
class DLLEXPORT Scene
#else
class Scene 
#endif
{
public:
	Scene(int);
    ~Scene();

	void addNewObject(int id, int xPos, int yPos, int height, int width);
	Object * getObject(int spriteID);

	int getSceneID() { return sceneID; }
	vector<Object*> getPtrToObjects() { return objects; }

private:
	int sceneID = 0;
	vector<Object*> objects;

};
