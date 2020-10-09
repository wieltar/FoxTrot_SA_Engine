
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
/// @param object 
void Scene::addNewObject(Object* object) 
{
	objects.push_back(object);
}

/// @brief 
/// @param objectID 
/// @return 
bool Scene::checkIfObjectExists(int objectID)
{
	for (Object* obj : objects)
	{
		if (obj->getSpriteID() == objectID)
		{
			return true;
		}
	}
	return false;
}

/// @brief 
/// @param id 
/// @param xPos 
/// @param yPos 
/// @param height 
/// @param width 
void Scene::addNewObject(int id, int xPos, int yPos, int height, int width,int speed, int jumpHeight, int density, int friction, int restitution, bool stat)
{
	Object* obj = new Object(id, xPos, yPos, height, width);
	obj->setDensity(density);
	obj->setFriction(friction);
	obj->setRestitution(restitution);
	obj->setJumpHeight(jumpHeight);
	obj->setSpeed(speed);
	obj->setStatic(stat);
	objects.push_back(obj);
}

/// @brief 
/// @param ObjectID 
/// @return 
Object * Scene::getObject(int objectID)
{
	for (Object * obj : objects)
	{
		if (obj->getSpriteID() == objectID)
		{
			return obj;
		}
	}
	throw ERROR_CODE_SCENE_NO_OBJECT_FOUND;
}
