#include "Object.h"


Object::Object()
{
}

Object::~Object()
{
}


int Object::getId() const {
    return id;
};
void Object::setName(std::string val) {
    name = val;
}
std::string Object::getName() {
    return name;
}
float Object::getX() const {
    return x;
}
void Object::setX(float val) {
    x = val;
}
float Object::getY() const {
    return y;
}
void Object::setY(float val) {
    y = val;
}
float Object::getWidth() const {
    return width;
}
void Object::setWidth(float val) {
    width = val;
}
float Object::getHeight() const {
    return height;
}
void Object::setHeight(float val) {
    height = val;
}
float Object::getRestitution() const {
    return restitution;
}
void Object::setRestitution(float val) {
    restitution = val;
}
float Object::getFriction() const {
    return friction;
}
void Object::setFriction(float val) {
    friction = val;
}
float Object::getDensity() const {
    return density;
}
void Object::setDensity(float val) {
    density = val;
}
float Object::getSpeed() const {
    return speed;
}
void Object::setSpeed(float val) {
    speed = val;
}
float Object::getJumpHeight() const {
    return jumpHeight;
}
void Object::setJumpHeight(float val) {
    jumpHeight = val;
}