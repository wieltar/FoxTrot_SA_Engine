#pragma once
#include "Component.h"

class Scene : public Component
{
public:
	Scene();
	~Scene();

private:
	uint16_t positionY = 0;
	uint16_t rotation = 0;
	uint16_t scale = 0;
};





