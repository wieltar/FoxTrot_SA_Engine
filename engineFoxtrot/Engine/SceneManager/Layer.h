#include "../stdafx.h"
#pragma once
#include "./Object.h"

struct Layer
{
	string layerIdentifier;
	bool render = false;
	vector<Object*> objects;
};