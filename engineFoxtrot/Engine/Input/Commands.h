#pragma once
#include "InputConstants.h"

class InputEngine;
class Command
{
public:
	Command() {};
	virtual ~Command() {};
	virtual void execute(InputEngine* inputEngine) = 0;
	InputType get_input_type() { return STATE; }
};


class MoveRight : public Command
{
public:
	void execute(InputEngine* inputEngine);
	InputType get_input_type() { return STATE; }
};


