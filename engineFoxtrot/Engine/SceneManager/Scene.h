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

	void createLayer(string layerIdentifier, bool render);
	bool toggleLayer(string layerIdentifier);

	bool addNewObjectToLayer(string layerIdentifier,Object* object);

	vector <Object*> getObjectsInLayer(string layerIdentifier);
	vector <Object*> getAllObjectsInScene();

	Object * getObject(const int objectID);

	int getSceneID() { return sceneID; }
	//vector<Object*> getObjectInLayer();

private:
	const int sceneID = 0;
	vector<Layer*> layers;

};
