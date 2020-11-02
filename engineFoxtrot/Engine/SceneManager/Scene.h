#pragma once

#include "Object.h"
#include "Layer.h"
#include "ParticleSystem/ParticleLib/ParticleInit.h"

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

	/// @brief
	/// OnAttach is executed when a scene is "attached" to the current running context
	/// usually this is can be used to prime a level with relevant data before starting it.
	/// Must be implemented by a concrete implementation of a scene
	virtual void OnAttach() = 0;
	/// @brief
	/// Start is called when a scene is ready to execute its logic, this can be percieved as the "main loop" of a scene
	/// Must be implemented by a concrete implementation of a scene
	virtual void Start() = 0;
	/// @brief
	/// OnDetach is called when a scene is destroyed/closed and is responsible for cleanup
	/// Must be implemented by a concrete implementation of a scene
	virtual void OnDetach() = 0;

private:
	const int sceneID = 0;
	map<int, Layer*> layers;


};
