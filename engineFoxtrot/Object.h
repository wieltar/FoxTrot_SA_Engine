#pragma once
#include <iostream>
#include <string>
#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

using namespace std;

/// @brief 
/// Object class. Object is linked with a sprite id in SVI. 

#if(EXPORT)
class DLLEXPORT Object
#else
class Object
#endif
{
public:
	Object(); 
	Object(int id);
	Object(int id, float xPos, float yPos, float height, float width);
	~Object();

	void setName(string);
	string getName() const;

	void setSpriteID(int);
	int getSpriteID() const;

	void setPositionX(float);
	float getPositionX() const;

	void setPositionY(float);
	float getPositionY() const;

	void setRotation(float);
	float getRotation() const;

	void setScale(float);
	float getScale() const;

	void setDirection(float);
	float getDirection() const;

	void setHeight(float);
	float getHeight() const;

	void setWidth(float);
	float getWidth() const;

	void setStatic(bool);
	bool getStatic() const;

	void setRestitution(float val);
	float getRestitution() const;

	void setFriction(float val);
	float getFriction() const;

	void setDensity(float val);
	float getDensity() const;

	void setSpeed(float val);
	float getSpeed() const;

	void setJumpHeight(float val);
	float getJumpHeight() const;

	bool getChanged() const;
private:

	std::string name;

	int spriteID = 0;
	float positionX = 0;
	float positionY = 0;
	float rotation = 0;
	float scale = 0;
	float direction = 0;
	float height = 0;
	float width = 0;
	float speed = 0;
	float jumpHeight = 0;
	float density = 0;
	float friction = 0;
	float restitution = 0;
	bool staticObject = false;
	bool changed = false;
};