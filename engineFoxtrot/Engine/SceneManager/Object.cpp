#include "stdafx.h"
#include "Object.h"

/// @brief 
Object::Object(const int _objectId) : objectId(_objectId)
{
}
/// @brief 
Object::~Object()
{
}

// Getters and setters

int Object::getObjectId() const { return objectId; }

void Object::setName(const std::string _name) { this->name = _name; }
std::string Object::getName() const {return name;}

void Object::setPositionX(const float x) { this->positionX = x; }
float Object::getPositionX() const { return positionX; }

void Object::setPositionY(const float y) { this->positionY = y; }
float Object::getPositionY() const { return positionY; }

void Object::setRotation(const float r) { this->rotation = r; }
float Object::getRotation() const { return rotation; }

void Object::setScale(const float s) { this->scale = s; }
float Object::getScale() const { return scale; }

void Object::setDirection(const float d) { this->direction = d; }
float Object::getDirection() const { return direction; }

void Object::setHeight(const float h) { this->height = h; }
float Object::getHeight() const { return height; }

void Object::setWidth(const float w) { this->width = w; }
float Object::getWidth() const { return width; }

void Object::setStatic(const bool s) { this->staticObject = s; }
bool Object::getStatic() const { return staticObject; }

float Object::getRestitution() const { return this->restitution;}
void Object::setRestitution(const float val) {this->restitution = val;}

float Object::getFriction() const {return this->friction;}
void Object::setFriction(const float val) {this->friction = val;}

float Object::getDensity() const {	return this->density;}
void Object::setDensity(const float val) {this->density = val;}

float Object::getSpeed() const {return this->speed;}
void Object::setSpeed(const float val) { this->speed = val; }

float Object::getJumpHeight() const {return this->jumpHeight;}
void Object::setJumpHeight(const float val) {	this->jumpHeight = val;}

bool Object::getChanged() const { return changed; }

SpriteObject* Object::GetCurrentSprite() { return currentSprite; }

/// @brief
/// register a new state or overwrite a existing state
/// register the spriteID
/// link a state with a sprite
void Object::registerSprite(const std::string state, const SpriteObject spriteObject) {
	textures[state] = spriteObject;
}

/// @brief
/// change the state
/// change the textureID to the current state
void Object::changeToState(const std::string state) {
	SpriteObject* spriteObject = &textures[state];
	if (spriteObject == NULL) throw ERROR_CODE_SPRITE_DOENST_EXIST;
	this->currentSprite = spriteObject;
}