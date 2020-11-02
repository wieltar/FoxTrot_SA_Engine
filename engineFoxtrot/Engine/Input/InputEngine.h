#pragma once
#include "InputFacade.h"
#include "Events/Action/ActionEvent.h"
#include "Events/EventSingleton.h"

/// @brief 
/// Input engine for handling input
class InputEngine
{
public:
	API InputEngine();
	API ~InputEngine();

	API void moveLeft();
	API void moveRight();
	API void jump();
	
	API bool fill(vector<Command*>& command_queue);
	API void configure(KeyCode key, Command* command);
	API void updateInput();
private:
	IInputFacade *inputFacade = new InputFacade();

	vector<Command*> commandQueue;
};
