#pragma once
#include <string>
#include "Direction.h"

class mObject {
protected:
    int unique_id;

    std::string name;
    std::string path;
    Direction direction;
    bool isStatic;
    int x;
    int y;
public:
    virtual std::string get_name() = 0;
    virtual void onCollision() = 0;
    virtual void move() = 0;
    virtual void interact() = 0;
    virtual void draw() = 0;
    virtual void animate() = 0;
    virtual void playSound() = 0;

    Direction getDirection() const { return this->direction; }
    std::string getPath() const { return this->path; }
    bool getIsStatic() const { return this->isStatic; }
    int getX() const { return this->x; }
    int getY() const { return this->y; }
    void setX(int newX) { this->x = newX; }
    void setY(int newY) { this->y = newY; }
};
