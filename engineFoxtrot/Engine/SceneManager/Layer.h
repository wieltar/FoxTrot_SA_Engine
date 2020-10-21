#include "../stdafx.h"
#pragma once
#include "./Object.h"

struct Layer
{
	bool render = false;
	vector<Object*> objects;
};