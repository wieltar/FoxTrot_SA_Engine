#pragma once

#include <vector>
#include "Object.h"

class Scene {
public:
    Scene();
    ~Scene();

    std::vector<Object*> objects = std::vector<Object*>();
};
