#pragma once
#include "InputConstants.h"
class InputEngine;

/// @brief Virtual class for all commands
class API Command
{
public:
	Command(InputEngine* inputEngine);
	virtual ~Command() {};
	virtual void execute() = 0;
	virtual InputType get_input_type() = 0;
protected:
	InputEngine* inputEngine;
};

/// @brief 
class API MoveLeft : public Command
{
public:
	MoveLeft(InputEngine* inputEngine);
	void execute();
	InputType get_input_type() { return STATE; }
};

/// @brief 
class API MoveRight : public Command
{
public:
	MoveRight(InputEngine* inputEngine);
	void execute();
	InputType get_input_type() { return STATE; }
};

/// @brief 
class API Jump : public Command
{
public:
	Jump(InputEngine* inputEngine);
	void execute();
	InputType get_input_type() { return STATE; }
};

/// @brief 
class ToggleFps : public Command
{
public:
	ToggleFps(InputEngine* inputEngine);
	void execute();
	InputType get_input_type() { return STATE; }
};




