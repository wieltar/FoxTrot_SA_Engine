#pragma once
#include "Object.h"

#if(EXPORT)
class DLLEXPORT EventListener
#else
class EventListener
#endif
{
public:
    virtual void update(Object* object) = 0;
};
