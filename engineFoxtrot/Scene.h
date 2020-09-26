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
    ~Scene();

	void getObject(int ObjectID);
	vector<Object*> returnCurrentObjects();

	//Todo
	// Set private:
	// private:
public:
	int sceneID;
	vector<Object*> Objects;

    uint16_t positionY = 0;
    uint16_t rotation = 0;
    uint16_t scale = 0;

};
