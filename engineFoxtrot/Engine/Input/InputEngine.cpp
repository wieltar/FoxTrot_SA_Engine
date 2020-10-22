#include "stdafx.h"
#include "InputEngine.h"

InputEngine::InputEngine()
{
	configure(97, new MoveRight());
	configure(98, new Jump());
}

InputEngine::~InputEngine()
{
}

void InputEngine::moveRight()
{
	cout << "Knop om naar rechts te lopen" << endl;
}

void InputEngine::jump()
{
	cout << "Jump ding" << endl;
}

bool InputEngine::fill(vector<Command*>& command_queue)
{
	return inputFacade->fill(command_queue);
}

void InputEngine::configure(int key, Command* command)
{
	inputFacade->configure(key, command);
}



