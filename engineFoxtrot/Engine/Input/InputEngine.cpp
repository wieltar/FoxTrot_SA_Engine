#include "stdafx.h"
#include "InputEngine.h"

/// @brief 
InputEngine::InputEngine()
{

}

/// @brief 
InputEngine::~InputEngine()
{
}

/// @brief 
/// Moveleft function called when a according key is pressed
void InputEngine::moveLeft()
{
	cout << "Knop om naar links te lopen" << endl;
}

/// @brief 
/// Moveright function called when a according key is pressed
void InputEngine::moveRight()
{
	cout << "Knop om naar rechts te lopen" << endl;
}

/// @brief 
/// Jump function called when a according key is pressed
void InputEngine::jump()
{
	cout << "Jump ding" << endl;
}

/// @brief 
/// @param command_queue 
/// @return 
bool InputEngine::fill(vector<Command*>& command_queue)
{
	return inputFacade->fill(command_queue);
}

/// @brief 
/// @param key 
/// @param command 
void InputEngine::configure(KeyCode key, Command* command)
{
	inputFacade->configure(key, command);
}



