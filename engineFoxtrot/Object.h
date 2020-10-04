#pragma once

#include <iostream>
#include <string>

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
};