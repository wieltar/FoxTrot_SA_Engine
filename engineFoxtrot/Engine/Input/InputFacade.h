#pragma once
#include "Commands.h"
#include "IInputFacade.h"

#include "InputConstants.h"
#include "Events/Codes/KeyCodes.h"

typedef union SDL_Event;
class InputEngine;

/// @brief Facade for SDL input part
class InputFacade : public IInputFacade
{

public:
    InputFacade(InputEngine* _inputEngine);
    ~InputFacade();

	bool fill(vector<Command*>& command_queue);
	void configure(KeyCode key, Command* command, bool runOnce);

private:
	InputEngine *inputEngine;
	bool input_mapping();
	void dispatcher(std::vector<Command*>& command_queue);

	void keydown(SDL_Event& event);
	void keyup(SDL_Event& event);

	bool is_held(int key);
	bool was_pressed(int key);

	map <KeyCode, State> state_map;
	map <KeyCode, Action> action_map;

	map <KeyCode, Command*> commands;
	vector<KeyCode> handleOnce;

	KeyCode eventToKeyCode(SDL_Event& event);
};



