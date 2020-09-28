
#include "Scene.h"

/// @brief 
/// @param sceneID 
Scene::Scene(int sceneID)
{
	this->sceneID = sceneID;
}

/// @brief 
Scene::~Scene()
{
}

/// @brief 
/// @param id 
/// @param xPos 
/// @param yPos 
/// @param height 
/// @param width 
void Scene::addNewObject(int id, int xPos, int yPos, int height, int width)
{
	objects.push_back(new Object(id, xPos, yPos, height, width));
}

/// @brief 
/// @param ObjectID 
/// @return 
Object * Scene::getObject(int ObjectID)
{
	for (Object * obj : objects)
	{
		if (obj->getSpriteID() == ObjectID)
		{
			return obj;
		}
	}
	throw ERROR_CODE_SCENE_NO_OBJECT_FOUND;
}
