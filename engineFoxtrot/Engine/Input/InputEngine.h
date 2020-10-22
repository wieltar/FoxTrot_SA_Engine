#pragma once
#include "InputFacade.h"

class InputEngine
{
public:
	InputEngine();
	~InputEngine();

	// Input Functions
	void input();

private:
	IInputFacade *inputFacade = new InputFacade();


};



