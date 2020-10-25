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
	void createNewScene(const int sceneID);
	void setCurrentScene(const int sceneID);
	Scene* getSceneWithID(const int sceneID);

	// Pointer
	vector <Object*> pointerToCurrentObjectVector;
protected:
	

private:

	// Helper Functions
	bool checkIfSceneExists(const int);

	Scene* currentScene = nullptr;
	vector<Scene*> scenes;

};
