#include "Object.h"


Object::Object()
{
}

Object::Object(int id, int xPos, int yPos, int height, int width)
{
	spriteID = id;
	positionX = xPos;
	positionY = yPos;
	this->height = height;
	this->width = width;
}

Object::~Object()
{
}