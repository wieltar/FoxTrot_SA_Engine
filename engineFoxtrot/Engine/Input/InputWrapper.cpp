#include "InputWrapper.h"

InputWrapper::InputWrapper()
{
}

InputWrapper::~InputWrapper()
{
}

void InputWrapper::setSimulationPointer(Simulation* simulation)
{
	inputFacade->setSimulationPointer(simulation);
}

bool InputWrapper::input_mapping()
{
	return inputFacade->input_mapping();
}
