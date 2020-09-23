#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include "input_commands.cpp"
#include "SDL.h"

class InputHandler {
	SDL_Event e;
	std::map <int, Command*> commands;

public:
	InputHandler() {
		commands[SDLK_d] = new MoveRight();
		commands[SDLK_a] = new MoveLeft();
		commands[SDLK_w] = new Jump();
		commands[SDLK_SPACE] = new Roll();
		commands[SDLK_q] = new Attack();
		commands[SDLK_e] = new Block();
	}

	void configureKey(int key, Command* command) {
		commands[key] = command;
	}

	void removeKey(int key) {
		if (commands[key] != NULL) {
			commands.erase(key);
		}
	}

	void handle() {
		while (SDL_PollEvent(&e)) {
			handlePressed(e);
		}
		handleCommands();
	}

	void handlePressed(SDL_Event e) {
		std::cout << e.key.keysym.sym << std::endl;
		Command* command = commands[e.key.keysym.sym];
		if (command != NULL) {
			if (e.type == SDL_KEYUP) {
				command->isActive = false;
			}
			else if (e.type == SDL_KEYDOWN) {
				command->isActive = true;
			}
		}
	}

	void handleCommands() {
		for (std::map<int, Command*>::iterator it = commands.begin(); it != commands.end(); ++it)
		{
			if (it->second != NULL && it->second->isActive) {
				it->second->execute();
			}
		}
	}
};