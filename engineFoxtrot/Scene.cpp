
#include "Scene.h"

/// @brief 
/// @param sceneID 
Scene::Scene(const int id) : sceneID(id)
{

}

/// @brief 
Scene::~Scene()
{
}

/// @brief 
/// Adds new object to the scene. If Object is empty function does not do anything. 
/// @param object 
/// Pointer to a new Object to be added to the Scene.
void Scene::addNewObject(Object* object) 
{
	if (object == nullptr) return;
	objects.push_back(object);
}

/// @brief 
/// Function for checking if an object with ObjectID exists in a Scene.
/// @param objectID 
/// Identifier for a ObjectID
/// @return 
/// Returns true if Object is found in current scene else false.
bool Scene::checkIfObjectExists(const int objectID)
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
/// @param speed 
/// @param jumpHeight 
/// @param density 
/// @param friction 
/// @param restitution 
/// @param stat 
void Scene::addNewObject(const int id, const int xPos, const int yPos, const int height, const int width, const int speed, const int jumpHeight, const int density, const int friction, const int restitution, const bool stat)
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
/// Returns the object matched with the given objectID, if none are found an error is thrown
/// @param ObjectID 
/// Identifier for objectID
/// @return 
/// Returns pointer to the found Object
Object * Scene::getObject(const int objectID)
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
