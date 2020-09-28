#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include "Object.h"
#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

using namespace std;

#include <vector>
#include "Object.h"

class Scene 
{
public:
    Scene();
	Scene(int);
    ~Scene();

	void addNewObject(int id, int xPos, int yPos, int height, int width);
	void getObject(int ObjectID);
	vector<Object*> returnCurrentObjects();

	//Todo
	// Set private:
	// private:
public:
	int sceneID;
	vector<Object*> objects;

    uint16_t positionY = 0;
    uint16_t rotation = 0;
    uint16_t scale = 0;

};
