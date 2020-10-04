#pragma once
#include <iostream>
#include <string>
#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

class Object {
private:
    std::string name = "";
    int id = 0;

    float x = 0;
    float y = 0;
    float width = 0;
    float height = 0;

    float density = 0;
    float friction = 0;
    float restitution = 0;

    float speed = 0;
    float jumpHeight = 0;
    float angle = 0;
public:



    Object();
    Object(int id) : id(id) { }
    ~Object();

    int getId() const;
    void setName(std::string val);
    std::string getName();
    float getX() const;
    void setX(float val);
    float getY() const;
    void setY(float val);
    float getWidth() const;
    void setWidth(float val);
    float getHeight() const;
    void setHeight(float val);
    float getRestitution() const;
    void setRestitution(float val);
    float getFriction() const;
    void setFriction(float val);
    float getDensity() const;
    void setDensity(float val);
    float getSpeed() const;
    void setSpeed(float val);
    float getJumpHeight() const;
    void setJumpHeight(float val);
    float getAngle() const;
    void setAngle(float val);
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