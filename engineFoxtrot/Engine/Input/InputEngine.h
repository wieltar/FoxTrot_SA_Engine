#pragma once
#include "InputFacade.h"

class InputEngine
{
public:
	InputEngine();
	~InputEngine();

	// Input Functions

	void moveRight();
	void jump();
	
	bool fill(vector<Command*>& command_queue);
	void configure(int key, Command* command);

private:
	IInputFacade *inputFacade = new InputFacade();


};



