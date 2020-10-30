#pragma once
#include "InputFacade.h"
#include "../Events/Action/ActionEvent.h"
#include "../Events/Action/FpsToggleEvent.h"
#include "../Events/EventSingleton.h"

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

	void toggleFps();
	
	bool fill(vector<Command*>& command_queue);
	void configure(KeyCode key, Command* command, bool runOnce);

	template <class T>
	T* makeCommand() {
		return new T(this);
	}

	void updateInput();
private:
	IInputFacade *inputFacade = new InputFacade();

	vector<Command*> commandQueue;
};
