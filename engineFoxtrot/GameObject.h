#pragma once

#include "Object.h"

class GameObject : public Object {
public:
    virtual void move() = 0;
};