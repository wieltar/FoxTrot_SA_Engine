#pragma once
#include "InputFacade.h"

/// @brief 
/// Input engine for handling input
class InputEngine
{
public:
	InputEngine();
	~InputEngine();

	void moveLeft();
	void moveRight();
	void jump();
	
	bool fill(vector<Command*>& command_queue);
	void configure(KeyCode key, Command* command);

private:
	IInputFacade *inputFacade = new InputFacade();


};



