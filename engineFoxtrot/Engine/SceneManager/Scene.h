#pragma once

#include "Object.h"
#include "Layer.h"

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

	// The order of creating layers it the order it will be displayed
	void createLayer(const string layerIdentifier, const bool render);
	void switchLayers(const string layer1, string layer2);
	const bool toggleLayer(const string layerIdentifier);

	const bool addNewObjectToLayer(const string layerIdentifier,Object* object);

	vector <Object*> getObjectsInLayer(const string layerIdentifier);
	vector <Object*> getAllObjectsInScene();

	Object * getObject(const int objectID);

	int getSceneID() { return sceneID; }

private:
	const int sceneID = 0;
	vector<Layer*> layers;

};
