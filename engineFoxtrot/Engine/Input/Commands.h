#pragma once
#include "InputConstants.h"
class InputEngine;

/// @brief Virtual class for all commands
class API Command
{
public:
	Command() {};
	virtual ~Command() {};
	virtual void execute(InputEngine* inputEngine) = 0;
	virtual InputType get_input_type() = 0;
};

/// @brief 
class API MoveLeft : public Command
{
public:
	void execute(InputEngine* inputEngine);
	InputType get_input_type() { return STATE; }
};

/// @brief 
class API MoveRight : public Command
{
public:
	void execute(InputEngine* inputEngine);
	InputType get_input_type() { return STATE; }
};

/// @brief 
class API Jump : public Command
{
public:
	void execute(InputEngine* inputEngine);
	InputType get_input_type() { return STATE; }
};


