#pragma once
#include "stdafx.h"
#include "InputFacade.h"

class InputWrapper
{
public:
	InputWrapper();
	~InputWrapper();

	void setSimulationPointer(Simulation* simulation);

	bool input_mapping();

private:
	IInputFacade *inputFacade = new InputFacade();


};



