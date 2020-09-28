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

	void setName(string);
	string getName();

	void setSpriteID(int);
	int getSpriteID();

	void setPositionX(int);
	int getPositionX();

	void setPositionY(int);
	int getPositionY();

	void setRotation(int);
	int getRotation();

	void setScale(int);
	int getScale();

	void setDirection(int);
	int getDirection();

	void setHeight(int);
	int getHeight();

	void setWidth(int);
	int getWidth();

	void setStatic(bool);
	bool getStatic();

	bool getChanged();
private:

	std::string name;

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
};