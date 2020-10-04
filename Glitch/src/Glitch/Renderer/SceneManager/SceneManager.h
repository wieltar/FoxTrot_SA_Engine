#pragma once
#include "Scene.h"
#include "Glitch/Core/ErrorCodes.h"

using namespace std;

/// @brief 
/// Contains all scenes. Manages all scenes and objects. All calls from engine containing object movements should be handled in the scene manager. 
namespace Glitch {
	class GLITCH_API SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		// Scene modifiers
		void createNewScene(int sceneID);
		void setCurrentScene(int sceneID);
		Scene* getSceneWithID(int sceneID);
		vector <Object*> pointerToCurrentObjectVector;

		// Object Modifiers
		void moveObject(int ObjectID, int X, int Y);
		void moveObjectRelative(int ObjectID, int moveXby, int moveYby);
		void rotateObject(int ObjectID, int rotation);
		void setObjectScale(int ObjectID, int scale);
		void setObjectDirection(int ObjectID, int dir);
		void setObjectStatic(int ObjectID, bool stat);

	private:

		bool checkIfSceneExists(int);

		Scene* currentScene = nullptr;
		vector<Scene*> scenes;

	};
}
