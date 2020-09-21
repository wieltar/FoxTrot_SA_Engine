#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include "Object.h"

using namespace std;

class Scene
{
public:
	Scene();
	~Scene();

	void getObject(int ObjectID);
	vector<Object*> returnCurrentObjects();

private:
	int sceneID;
	vector<Object*> Objects;
};





