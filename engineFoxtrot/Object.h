#pragma once
#include <iostream>
#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

using namespace std;

class Object
{
public:
	Object();
	~Object();

private:

	uint16_t spriteID = 0;
	uint16_t positionX = 0;
	uint16_t positionY = 0;
	uint16_t rotation = 0;
	uint16_t scale = 0;
	uint16_t direction = 0;
	bool staticObject = false;
	bool changed = false;

};



