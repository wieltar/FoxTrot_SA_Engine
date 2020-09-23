#pragma once

#include "mObject.h"

class GameObject : public mObject {
public:
    virtual std::string get_name() = 0;
    virtual void onCollision() = 0;
    virtual void move() = 0;
    virtual void interact() = 0;
    virtual void draw() = 0;
    virtual void animate() = 0;
    virtual void playSound() = 0;
};