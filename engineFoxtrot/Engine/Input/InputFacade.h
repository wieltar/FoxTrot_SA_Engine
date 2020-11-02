#pragma once
#include "Commands.h"
#include "InputConstants.h"
#include "Events/Codes/KeyCodes.h"

#include "IInputFacade.h"

union SDL_Event;

/// @brief Facade for SDL input part
class InputFacade : public IInputFacade
{

public:
    InputFacade();
    ~InputFacade();

	bool fill(vector<Command*>& command_queue);
	void configure(KeyCode key, Command* command);
private:
	bool input_mapping();
	void dispatcher(std::vector<Command*>& command_queue);

	void keydown(SDL_Event& event);
	void keyup(SDL_Event& event);

	State is_held(KeyCode key);
	Action was_pressed(KeyCode key);

	map <KeyCode, State> state_map;
	map <KeyCode, Action> action_map;

	map <KeyCode, Command*> commands;

	KeyCode eventToKeyCode(SDL_Event& event);
};



