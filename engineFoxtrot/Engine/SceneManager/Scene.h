#pragma once

#include "Object.h"
#include "Layer.h"

/// @brief 
/// Scene Class
/// Contains all the objects that should be drawn in this scene.

class Scene 
{
public:
	API Scene(const int);
	API~Scene();

	bool API checkIfObjectExists(const int objectID);
	const bool API toggleLayer(const int zIndex, bool render);
	const void API addNewObjectToLayer(const int zIndex,Object* object);

	vector <Object*> API getAllObjectsInScene();

	Object API *getObject(const int objectID);

	int API getSceneID() { return sceneID; }

private:
	const int sceneID = 0;
	std::map<int, Layer*> layers;


};
