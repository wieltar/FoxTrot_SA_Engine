#pragma once
#include "Component.h"

class Scene: public Component
{
private:
	uint16_t positionY;
	uint16_t rotation;
	uint16_t scale;
};

