#pragma once
#include "InputConstants.h"

class InputEngine;

/// @brief Virtual class for all commands
class Command
{
public:
	Command(InputEngine* inputEngine) {};
	virtual ~Command() {};
	virtual void execute() = 0;
	virtual InputType get_input_type() = 0;
protected:
	InputEngine* inputEngine;
};

/// @brief 
class MoveLeft : public Command
{
public:
	void execute();
	InputType get_input_type() { return STATE; }
};

/// @brief 
class MoveRight : public Command
{
public:
	void execute();
	InputType get_input_type() { return STATE; }
};

/// @brief 
class Jump : public Command
{
public:
	void execute();
	InputType get_input_type() { return STATE; }
};

/// @brief 
class ToggleFps : public Command
{
public:
	void execute();
	InputType get_input_type() { return STATE; }
};




