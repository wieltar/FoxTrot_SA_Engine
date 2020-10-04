#pragma once
#include "Glitch/Core/Object.h"

using namespace std;

/// @brief 
/// Scene Class
/// Contains all the objects that should be drawn in this scene.
namespace Glitch {
	class GLITCH_API Scene
	{
	public:
		Scene(int);
		~Scene();

		void addNewObject(int id, int xPos, int yPos, int height, int width);
		Object* getObject(int spriteID);

		int getSceneID() { return sceneID; }
		vector<Object*> getPtrToObjects() { return objects; }

	private:
		int sceneID = 0;
		vector<Object*> objects;

	};
}