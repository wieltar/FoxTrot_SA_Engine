#pragma once
// TODO find out why removing this breaks everything
#include "stdafx.h"
/// @brief 
/// Object class. Object is linked with a sprite id in SVI. 
class Object
{
public:
	API Object(const int id);
	API Object(const int id, const float xPos, const float yPos, const float height, const float width);
	API ~Object();

	void API setName(const string val);
	string API getName() const;

	int API getSpriteID() const;

	void API setPositionX(const float);
	float API getPositionX() const;

	void API setPositionY(const float);
	float API getPositionY() const;

	void API setRotation(const float);
	float API getRotation() const;

	void API setScale(const float);
	float API getScale() const;

	void API setDirection(const float);
	float API getDirection() const;

	void API setHeight(const float);
	float API getHeight() const;

	void API setWidth(const float);
	float API getWidth() const;

	void API setStatic(const bool);
	bool API getStatic() const;

	void API setRestitution(const float val);
	float API getRestitution() const;

	void API setFriction(const float val);
	float API getFriction() const;

	void API setDensity(const float val);
	float API getDensity() const;

	void API setSpeed(const float val);
	float API getSpeed() const;

	void API setJumpHeight(const float val);
	float API getJumpHeight() const;

	bool API getChanged() const;

private:
	string name;

	const int spriteID = 0;
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