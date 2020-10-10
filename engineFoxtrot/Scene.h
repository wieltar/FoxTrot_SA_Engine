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
	Scene(const int);
    ~Scene();

	bool checkIfObjectExists(const int objectID);
	void addNewObject(Object* object);
	void addNewObject(const int id, const int xPos, const int yPos, const int height, const int width, const int speed, const int jumpHeight, const int density, const int friction, const int restitution, const bool stat);
	Object * getObject(const int objectID);

	int getSceneID() { return sceneID; }
	vector<Object*> getPtrToObjects() { return objects; }

private:
	const int sceneID = 0;
	vector<Object*> objects;

};
