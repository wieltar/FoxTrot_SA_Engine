#pragma once
#include "Events/Codes/KeyCodes.h"

/// @brief 
/// Interface Inputfacade 
class IInputFacade
{
public:
	IInputFacade() {};
	~IInputFacade() {};

	virtual void pollEvents() = 0;
	virtual bool fill(vector<Command*>& command_queue) = 0;
	virtual void configure(KeyCode key, Command* command) = 0;
private:

};
