#pragma once


#include "IInputFacade.h"

class InputFacade : public IInputFacade
{

public:
    InputFacade();
    ~InputFacade();

	void input();

private:
	int mousex = 0;
	int mousey = 0;


};



