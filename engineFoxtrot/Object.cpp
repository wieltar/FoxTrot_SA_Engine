#include "Object.h"


Object::Object()
{
}

Object::~Object()
{
}


int Object::getId() const {  return this->id; };
void Object::setName(std::string val) { this->name = val; }
std::string Object::getName() { return this->name; }

// TODO seperate classes
float Object::getX() const {
    return this->x;
}
void Object::setX(float val) {
    this->x = val;
}
float Object::getY() const {
    return this->y;
}
void Object::setY(float val) {
    this->y = val;
}
float Object::getWidth() const {
    return this->width;
}
void Object::setWidth(float val) {
    this->width = val;
}
float Object::getHeight() const {
    return this->height;
}
void Object::setHeight(float val) {
    this->height = val;
}
float Object::getRestitution() const {
    return this->restitution;
}
void Object::setRestitution(float val) {
    this->restitution = val;
}
float Object::getFriction() const {
    return this->friction;
}
void Object::setFriction(float val) {
    this->friction = val;
}
float Object::getDensity() const {
    return this->density;
}
void Object::setDensity(float val) {
    this->density = val;
}
float Object::getSpeed() const {
    return this->speed;
}
void Object::setSpeed(float val) {
    this->speed = val;
}
float Object::getJumpHeight() const {
    return this->jumpHeight;
}
void Object::setJumpHeight(float val) {
    this->jumpHeight = val;
}