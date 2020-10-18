#pragma once
#include "stdafx.h"

class IInputFacade
{
public:
	IInputFacade() {};
	~IInputFacade() {};

	virtual void setSimulationPointer(Simulation* simulation) = 0;
	virtual bool input_mapping() = 0;

private:

};
