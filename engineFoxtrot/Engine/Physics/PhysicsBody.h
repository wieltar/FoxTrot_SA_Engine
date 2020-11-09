#pragma once
#include "../SceneManager/Object.h"

class PhysicsBody
{
public:
	PhysicsBody(Object* object);
	~PhysicsBody();
	int getObjectId() const;

	void setPositionX(const float);
	float getPositionX() const;

	void setPositionY(const float);
	float getPositionY() const;

	void setRotation(const float);
	float getRotation() const;

	void setHeight(const float);
	float getHeight() const;

	void setWidth(const float);
	float getWidth() const;

	void setRestitution(const float);
	float getRestitution() const;

	void setFriction(const float);
	float getFriction() const;

	void setDensity(const float);
	float getDensity() const;

	void setSpeed(const float);
	float getSpeed() const;

	void setJumpHeight(const float);
	float getJumpHeight() const;

	void setYAxisVelocity(const float val);
	float getYAxisVelocity() const;

	void setXAxisVelocity(const float val);
	float getXAxisVelocity() const;

	void setRotatable(const bool val);
	bool getRotatable() const;
protected:
	int objectID = 0;
	float height = 0;
	float width = 0;
	float posX = 0;
	float posY = 0;
	float speed = 0;
	float friction = 0;
	float restitution = 0;
	float density = 0;
	float rotation = 0;
	float jumpHeight = 0;
	Object* object = nullptr;
	float yAxisVelocity = 0;
	float xAxisVelocity = 0;
	bool rotatable = false;
};
