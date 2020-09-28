
#include "Scene.h"


Scene::Scene()
{
}

Scene::Scene(int sceneID)
{
	this->sceneID = sceneID;
}

Scene::~Scene()
{
}

void Scene::addNewObject(int id, int xPos, int yPos, int height, int width)
{
	objects.push_back(new Object(id, xPos, yPos, height, width));
}

Object * Scene::getObject(int ObjectID)
{
	for (Object * obj : objects)
	{
		if (obj->getSpriteID() == ObjectID)
		{
			return obj;
		}
	}
}
