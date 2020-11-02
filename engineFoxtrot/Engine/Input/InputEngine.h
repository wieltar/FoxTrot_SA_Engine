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

	/// @brief
	/// Generic function for creating command externally
	template <class T>
	T* makeCommand() {
		static_assert(is_base_of<Command, T>::value, "Type parameter for this function must derive from Command");
		return new T(this);
	}

	void updateInput();
private:
	IInputFacade *inputFacade = new InputFacade();

	vector<Command*> commandQueue;
};
