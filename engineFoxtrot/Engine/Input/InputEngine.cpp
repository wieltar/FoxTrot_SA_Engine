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
	// TODO Get object Id where player
	EventSingleton::get_instance().dispatchEvent<ActionEvent>((Event&)ActionEvent(Direction::LEFT, 2));
	cout << "Knop om naar links te lopen" << endl;
}

/// @brief 
/// Moveright function called when a according key is pressed
void InputEngine::moveRight()
{
	// TODO Get object Id where player
	EventSingleton::get_instance().dispatchEvent<ActionEvent>((Event&)ActionEvent(Direction::RIGHT, 2));
	cout << "Knop om naar rechts te lopen" << endl;
}

/// @brief 
/// Jump function called when a according key is pressed
void InputEngine::jump()
{
	// TODO Get object Id where player
	EventSingleton::get_instance().dispatchEvent<ActionEvent>((Event&)ActionEvent(Direction::UP, 2));
	cout << "Jump ding" << endl;
}

/// @brief 
/// Executes the events from polling
void InputEngine::updateInput()
{
	this->fill(commandQueue);

	while (!commandQueue.empty()) {
		commandQueue.back()->execute(this);
		commandQueue.pop_back();
	}
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

