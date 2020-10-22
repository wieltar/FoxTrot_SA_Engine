#pragma once


class IInputFacade
{
public:
	IInputFacade() {};
	~IInputFacade() {};


	virtual bool input_mapping() = 0;

private:

};
