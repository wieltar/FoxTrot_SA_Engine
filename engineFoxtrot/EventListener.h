#pragma once
#include "Object.h"

class EventListener {
public:
    virtual void update(Object* object) = 0;
};
