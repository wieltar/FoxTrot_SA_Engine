#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include "input_commands.cpp"
#include "SDL.h"

class input {
	SDL_Event e;
	int mouseX;
	int mouseY;
	std::map <int, Command*> keyCommands;
	std::map<int, Command*> mouseCommands;

public:
	input() {
		keyCommands[SDLK_d] = new MoveRight();
		keyCommands[SDLK_a] = new MoveLeft();
		keyCommands[SDLK_w] = new Jump();
		keyCommands[SDLK_SPACE] = new Roll();

		mouseCommands[MouseButton::Left] = new Attack();
		mouseCommands[MouseButton::Right] = new Block();
	}

	void configureKey(int key, Command* command) {
		keyCommands[key] = command;
	}

	void removeKey(int key) {
		if (keyCommands[key] != NULL) {
			keyCommands.erase(key);
		}
	}

	void handle() {
		SDL_GetMouseState(&mouseX, &mouseY);
		while (SDL_PollEvent(&e)) {
			handlePressed(e);
		}
		handleCommands();
	}

	void handlePressed(SDL_Event e) {
		if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
			Command* command = mouseCommands[e.button.button];
			if (command != NULL) {
				command->isActive = !command->isActive;
				command->event = *(new InputEvent(InputType::Key, 0, &mouseX, &mouseY));
			}
		}
		Command* command = keyCommands[e.key.keysym.sym];
		if (command != NULL) {
			if (e.type == SDL_KEYUP) {
				command->isActive = false;
			}
			else if (e.type == SDL_KEYDOWN) {
				command->isActive = true;
				command->event = *(new InputEvent(InputType::Key, e.key.keysym.sym));
			}
		}
	}

	void handleCommands() {
		for (std::map<int, Command*>::iterator it = keyCommands.begin(); it != keyCommands.end(); ++it)
		{
			if (it->second != NULL && it->second->isActive) {
				it->second->execute();
			}
		}
		for (std::map<int, Command*>::iterator it = mouseCommands.begin(); it != mouseCommands.end(); ++it)
		{
			if (it->second != NULL && it->second->isActive) {
				it->second->execute();
			}
		}
	}
};