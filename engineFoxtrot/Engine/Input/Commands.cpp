#include "stdafx.h"
#include "Commands.h"
#include "InputEngine.h"

/// @brief 
/// Execute function for Moveleft
/// @param inputEngine 
void MoveLeft::execute(InputEngine* inputEngine)
{
	inputEngine->moveLeft();
}

/// @brief 
/// Execute function for moveRight
/// @param inputEngine 
void MoveRight::execute(InputEngine* inputEngine)
{
	inputEngine->moveRight();
}

/// @brief 
/// Execute function for jumping
/// @param inputEngine 
void Jump::execute(InputEngine* inputEngine)
{
	inputEngine->jump();
}