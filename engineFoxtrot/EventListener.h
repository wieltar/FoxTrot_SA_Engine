#pragma once
#include "Object.h"

class EventListener {
public:
    virtual void update(Object* o) = 0;
};
