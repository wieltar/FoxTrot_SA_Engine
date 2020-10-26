#pragma once
#include "Scene.h"



/// @brief 
/// Contains all scenes. Manages all scenes and objects.
#if(EXPORT)
class DLLEXPORT SceneManager
#else
class SceneManager
#endif
{
public:
	SceneManager();
	~SceneManager();

	// Scene modifiers
	void setCurrentScene(const int sceneID);
	Scene* getSceneWithID(const int sceneID);
	void insertScene(Scene* scene);

	// Pointer
	Scene* currentScene = nullptr;

protected:
	

private:

	// Helper Functions
	bool checkIfSceneExists(const int);

	vector<Scene*> scenes;

};
