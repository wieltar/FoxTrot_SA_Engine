#pragma once
#include "InputFacade.h"
#include "../Events/Action/ActionEvent.h"
#include "../Events/EventSingleton.h"
#include "core.h"

/// @brief 
/// Input engine for handling input
class API InputEngine
{
public:
	InputEngine();
	~InputEngine();

	void moveLeft();
	void moveRight();
	void jump();
	
	bool fill(vector<Command*>& command_queue);
	void configure(KeyCode key, Command* command);
	void updateInput();
private:
	IInputFacade *inputFacade = new InputFacade();

	vector<Command*> commandQueue;
};
