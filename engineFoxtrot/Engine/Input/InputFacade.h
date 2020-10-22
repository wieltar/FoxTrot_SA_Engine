#pragma once
#include "Commands.h"
#include "IInputFacade.h"

#include "InputConstants.h"

typedef union SDL_Event;

/// @brief 
class InputFacade : public IInputFacade
{

public:
    InputFacade();
    ~InputFacade();


	bool fill(vector<Command*>& command_queue);
	void configure(int key, Command* command);

private:
	bool input_mapping();
	void dispatcher(std::vector<Command*>& command_queue);

	void keydown(SDL_Event& event);
	void keyup(SDL_Event& event);

	bool is_held(int key);
	bool was_pressed(int key);

	int mousex = 0;
	int mousey = 0;

	map <int, State> state_map;
	map <int, Action> action_map;

	map <int, Command*> commands;

};



