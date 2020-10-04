#include "Object.h"

/// @brief 
Object::Object()
{
}

/// @brief 
/// @param id 
/// @param xPos 
/// @param yPos 
/// @param height 
/// @param width 
Object::Object(int id, int xPos, int yPos, int height, int width)
{
	spriteID = id;
	positionX = xPos;
	positionY = yPos;
	this->height = height;
	this->width = width;
}

/// @brief 
Object::~Object()
{
}
int Object::getId() { return this->id; }

void Object::setName(string n) { this->name = n; }
string Object::getName() { return name; }

void Object::setSpriteID(int s) { this->spriteID = s; }
int Object::getSpriteID() { return spriteID; }

void Object::setPositionX(int x) { this->positionX = x; }
float Object::getPositionX() { return positionX; }

void Object::setPositionY(int y) { this->positionY = y; }
float Object::getPositionY() { return positionY; }

void Object::setRotation(int r) { this->rotation = r; }
float Object::getRotation() { return rotation; }

void Object::setScale(int s) { this->scale = s; }
float Object::getScale() { return scale; }

void Object::setDirection(int d) { this->direction = d; }
int Object::getDirection() { return direction; }

void Object::setHeight(int h) { this->height = h; }
float Object::getHeight() { return height; }

void Object::setWidth(int w) { this->width = w; }
float Object::getWidth() { return width; }

void Object::setStatic(bool s) { this->staticObject = s; }
bool Object::getStatic() { return staticObject; }

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

float Object::getAngle() const {return this->angle;}
void Object::setAngle(float val) {this->angle = val;}

bool Object::getChanged() { return changed; }