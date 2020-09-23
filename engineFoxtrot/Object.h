#pragma once
#include <iostream>

using namespace std;

class Object
{
public:
	Object();
	~Object();

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



