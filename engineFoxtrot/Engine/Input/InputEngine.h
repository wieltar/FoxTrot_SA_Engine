#pragma once

#include "InputFacade.h"
#include "Events/Action/ActionEvent.h"
#include "Events/Action/FpsToggleEvent.h" //TODO check this
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
	API void configure(KeyCode key, Command* command, bool runOnce);
	API void updateInput();

	API void toggleFps();
	
	/// @brief
	/// Generic function for creating command externally
	template <class T>
	T* makeCommand() {
		static_assert(is_base_of<Command, T>::value, "Type parameter for this function must derive from Command");
		return new T(this);
	}
private:
	IInputFacade *inputFacade = new InputFacade();

	vector<Command*> commandQueue;
};
