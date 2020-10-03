#pragma once
#include <vector> 

class Component
{
public:
	Component();
	~Component();

private:
	std::vector<Component*> children;
};





