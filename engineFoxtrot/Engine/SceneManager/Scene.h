#pragma once

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
	Object * getObject(const int objectID);

	int getSceneID() { return sceneID; }
	vector<Object*> getPtrToObjects() { return objects; }

private:
	const int sceneID = 0;
	vector<Object*> objects;

};
