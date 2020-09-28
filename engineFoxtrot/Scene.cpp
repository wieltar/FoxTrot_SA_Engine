
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

void Scene::getObject(int ObjectID)
{
}

vector<Object*> Scene::returnCurrentObjects()
{
	return objects;
}
