#pragma once
#include "mObject.h"

class EventListener {
public:
    virtual void update(mObject* o) = 0;
};
