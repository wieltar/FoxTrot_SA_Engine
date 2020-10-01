#pragma once

#include <vector>
#include "Object.h"

class Scene 
{
public:
    Scene();
    ~Scene();

private:
    uint16_t positionY = 0;
    uint16_t rotation = 0;
    uint16_t scale = 0;
};
