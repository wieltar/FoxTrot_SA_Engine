#pragma once
#include "Events/Codes/KeyCodes.h"
class Command;
/// @brief 
/// Interface Inputfacade 
class IInputFacade
{
public:
	IInputFacade() {};
	~IInputFacade() {};

	virtual void pollEvents() = 0;
private:

};
