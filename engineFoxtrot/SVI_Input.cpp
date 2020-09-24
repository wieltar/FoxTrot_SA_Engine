#include <map>
#include <functional>
#include "SVI.h"

// Functions in this cpp file may only call functions in this file. And global SDL2 definitions

enum MouseButton {
	None,
	Left,
	Middle,
	Right
};
enum InputType {
	Key,
	Button
};
class InputEvent {
public:
	InputType type;
	int value;
	int* x;
	int* y;
	InputEvent(InputType t, int v, int* px = 0, int* py = 0) {
		type = t;
		value = v;
		x = px;
		y = py;
	};
	InputEvent() {
		type = InputType::Key;
		value = 0;
		x = 0;
		y = 0;
	}
};
class Command {
public:
	Command() {};
	virtual ~Command() {}
	void(*callback);
	bool isActive = false;
	InputEvent event;
};

std::map <int, Command*> keyCommands;
std::map<int, Command*> mouseCommands;

SDL_Event e;
int mouseX;
int mouseY;

void saveCommand(Command* command, int inputType, int key, int mouseBtn) {
	if (inputType == InputType::Key) {
		keyCommands[key] = command;
	}
	else if (inputType == InputType::Button) {
		MouseButton btn;
		try
		{
			btn = MouseButton(mouseBtn);
		}
		catch (const std::exception&)
		{

		}
		mouseCommands[mouseBtn] = command;
	}
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
			it->second->callback;
		}
	}
	for (std::map<int, Command*>::iterator it = mouseCommands.begin(); it != mouseCommands.end(); ++it)
	{
		if (it->second != NULL && it->second->isActive) {
			it->second->callback;
		}
	}
}

void SVI::RegisterCommand(void(*callback), int inputType, int key, int mouseBtn) {
	Command* command = new Command;
	command->callback = &callback;
	saveCommand(command, inputType, key, mouseBtn);
}

void SVI::input() {
	SDL_GetMouseState(&mouseX, &mouseY);
	while (SDL_PollEvent(&e)) {
		handlePressed(e);
	}
	handleCommands();
}