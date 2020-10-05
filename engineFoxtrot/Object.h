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
	Object(int id) : id(id) { }
	Object(int id, int xPos, int yPos, int height, int width);
	~Object();
	int getId() const;

	void setName(string);
	string getName() const;

	void setSpriteID(int);
	int getSpriteID() const;

	void setPositionX(int);
	float getPositionX() const;

	void setPositionY(int);
	float getPositionY() const;

	void setRotation(int);
	float getRotation() const;

	void setScale(int);
	float getScale() const;

	void setDirection(int);
	int getDirection() const;

	void setHeight(int);
	float getHeight() const;

	void setWidth(int);
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

	void setAngle(float val);
	float getAngle() const;

	bool getChanged() const;
private:

	std::string name;

	int id = 0;
	int spriteID = 0;
	float positionX = 0;
	float positionY = 0;
	float rotation = 0;
	float scale = 0;
	float direction = 0;
	float height = 0;
	float width = 0;
	float speed = 0;
	float angle = 0;
	float jumpHeight = 0;
	float density = 0;
	float friction = 0;
	float restitution = 0;
	bool staticObject = false;
	bool changed = false;
};