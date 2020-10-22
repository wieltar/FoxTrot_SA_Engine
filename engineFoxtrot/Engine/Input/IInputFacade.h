#pragma once

/// @brief 
/// Interface Inputfacade 
class IInputFacade
{
public:
	IInputFacade() {};
	~IInputFacade() {};

	virtual bool fill(vector<Command*>& command_queue) = 0;
	virtual void configure(int key, Command* command) = 0;

private:

};
