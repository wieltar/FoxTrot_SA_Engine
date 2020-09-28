#pragma once
#include <iostream>
#include <string>
#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

using namespace std;

class Object
{
public:
	Object();
	Object(int id, int xPos, int yPos, int height, int width);
	~Object();

	std::string name;

	// TODO: Set to private after testing
	int spriteID = 0;
	int positionX = 0;
	int positionY = 0;
	int rotation = 0;
	int scale = 0;
	int direction = 0;
	int height = 0;
	int width = 0;
	bool staticObject = false;
	bool changed = false;

private:

};