#include "stdafx.h"
#include "Commands.h"
#include "InputEngine.h"

Command::Command(InputEngine* _inputEngine) : inputEngine(_inputEngine) {}

/// @brief 
/// Execute function for Moveleft
void MoveLeft::execute()
{
	inputEngine->moveLeft();
}

/// @brief 
/// Execute function for moveRight
void MoveRight::execute()
{
	inputEngine->moveRight();
}

/// @brief 
/// Execute function for jumping
void Jump::execute()
{
	inputEngine->jump();
}

/// @brief
///  Execute function for toggling fps
void ToggleFps::execute() {
	inputEngine->toggleFps();
}