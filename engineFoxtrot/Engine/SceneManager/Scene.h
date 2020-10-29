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
	const bool toggleLayer(const int zIndex, bool render);
	const void addNewObjectToLayer(const int zIndex,Object* object);

	vector <Object*> getAllObjectsInScene();

	Object * getObject(const int objectID);

	int getSceneID() { return sceneID; }


	virtual void OnAtach();//load all sounds
	virtual void Start();//play 1 select sound
	virtual void OnDetach();//cleaup buffer

private:
	const int sceneID = 0;
	std::map<int, Layer*> layers;


};
