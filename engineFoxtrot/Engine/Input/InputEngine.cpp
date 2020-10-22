#include "stdafx.h"
#include "InputEngine.h"

InputEngine::InputEngine()
{
}

InputEngine::~InputEngine()
{
}

/// @brief 
/// Receives input
void InputEngine::input()
{
	inputFacade->input();
}

