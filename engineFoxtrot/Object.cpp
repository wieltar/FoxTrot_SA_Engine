#include "Object.h"

/// @brief 
Object::Object()
{
}

/// @brief 
Object::Object(int id) : spriteID(id)
{
}

/// @brief 
/// @param id 
/// @param xPos 
/// @param yPos 
/// @param height 
/// @param width 
Object::Object(int id, float xPos, float yPos, float height, float width) : spriteID(id)
{
	positionX = xPos;
	positionY = yPos;
	this->height = height;
	this->width = width;
}

/// @brief 
Object::~Object()
{
}
void Object::setName(string n) { this->name = n; }
string Object::getName() const { return name; }

int Object::getSpriteID() const { return spriteID; }

void Object::setPositionX(float x) { this->positionX = x; }
float Object::getPositionX() const { return positionX; }

void Object::setPositionY(float y) { this->positionY = y; }
float Object::getPositionY() const { return positionY; }

void Object::setRotation(float r) { this->rotation = r; }
float Object::getRotation() const { return rotation; }

void Object::setScale(float s) { this->scale = s; }
float Object::getScale() const { return scale; }

void Object::setDirection(float d) { this->direction = d; }
float Object::getDirection() const { return direction; }

void Object::setHeight(float h) { this->height = h; }
float Object::getHeight() const { return height; }

void Object::setWidth(float w) { this->width = w; }
float Object::getWidth() const { return width; }

void Object::setStatic(bool s) { this->staticObject = s; }
bool Object::getStatic() const { return staticObject; }

float Object::getRestitution() const { return this->restitution;}
void Object::setRestitution(float val) {this->restitution = val;}

float Object::getFriction() const {return this->friction;}
void Object::setFriction(float val) {this->friction = val;}

float Object::getDensity() const {	return this->density;}
void Object::setDensity(float val) {this->density = val;}

float Object::getSpeed() const {return this->speed;}
void Object::setSpeed(float val) { this->speed = val; }

float Object::getJumpHeight() const {return this->jumpHeight;}
void Object::setJumpHeight(float val) {	this->jumpHeight = val;}

bool Object::getChanged() const { return changed; }