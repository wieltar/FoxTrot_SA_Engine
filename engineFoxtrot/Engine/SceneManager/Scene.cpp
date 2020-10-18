#include "stdafx.h"
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
/// Function for checking if an object with ObjectID exists in a Scene.
/// @param objectID 
/// Identifier for a ObjectID
/// @return 
/// Returns true if Object is found in current scene else false.
bool Scene::checkIfObjectExists(const int objectID)
{
	for (Object* obj : getAllObjectsInScene())
	{
		if (obj->getSpriteID() == objectID)
		{
			return true;
		}
	}
	return false;
}

void Scene::switchLayers(const string layer1, const string layer2)
{
	int layer1Pos = 0, layer2Pos = 0;
	int count = 0;
	for (auto layer : layers)
	{
		if (layer->layerIdentifier == layer1)
		{
			layer1Pos = count;
		}
		else if (layer->layerIdentifier == layer2)
		{
			layer2Pos = count;
		}
		count++;
	}
	if (layer1Pos != layer2Pos)
	{
		swap(layers[layer1Pos], layers[layer2Pos]);
	}
}

void Scene::createLayer(const string layerIdentifier, const bool render)
{
	cout << "Creating new layer with identifier " << layerIdentifier << endl;
	Layer * layer = new Layer;
	layer->layerIdentifier = layerIdentifier;
	layer->render = render;
	layers.push_back(layer);
}

const bool Scene::toggleLayer(const string layerIdentifier)
{
	for (auto layer : layers)
	{
		if (layer->layerIdentifier == layerIdentifier) layer->render = !layer->render;
		return layer->render;
	}
	return false;
}

vector <Object*> Scene::getObjectsInLayer(const string layerIdentifier)
{
	for (auto layer : layers)
	{
		if (layer->layerIdentifier == layerIdentifier)
		{
			return layer->objects;
		}
	}
}

vector <Object*> Scene::getAllObjectsInScene()
{
	vector <Object*> returnVector;
	for (auto layer : layers)
	{
		returnVector.insert(returnVector.end(), layer->objects.begin(), layer->objects.end());
	}
	return returnVector;
}

const bool Scene::addNewObjectToLayer(const string layerIdentifier, Object* object)
{
	if (layerIdentifier == "") return false;
	if (object == nullptr) return false;

	for (Layer * layer : layers)
	{
		if (layer->layerIdentifier == layerIdentifier)
		{
			cout << "Layer found, adding Object" << endl;
			layer->objects.push_back(object);
			return true;
		}
	}
	createLayer(layerIdentifier,false);
	return addNewObjectToLayer(layerIdentifier, object);
}

/// @brief 
/// Returns the object matched with the given objectID, if none are found an error is thrown
/// @param ObjectID 
/// Identifier for objectID
/// @return 
/// Returns pointer to the found Object
Object * Scene::getObject(const int objectID)
{
	for (Object * obj : getAllObjectsInScene())
	{
		if (obj->getSpriteID() == objectID)
		{
			return obj;
		}
	}
	throw ERROR_CODE_SCENE_NO_OBJECT_FOUND;
}
