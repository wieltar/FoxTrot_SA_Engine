#pragma once


#include "IInputFacade.h"

typedef union SDL_Event;

class InputFacade : public IInputFacade
{

public:
    InputFacade();
    ~InputFacade();

	bool input_mapping();
	void keydown(SDL_Event& event);


private:
	int mousex = 0;
	int mousey = 0;


};



