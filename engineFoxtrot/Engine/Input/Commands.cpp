#include "stdafx.h"
#include "Commands.h"
#include "InputEngine.h"

Command::Command(InputEngine* _inputEngine) : inputEngine(_inputEngine) {}

MoveLeft::MoveLeft(InputEngine* _inputEngine) : Command(inputEngine) {}

/// @brief 
/// Execute function for Moveleft
void MoveLeft::execute()
{
	inputEngine->moveLeft();
}

MoveRight::MoveRight(InputEngine* _inputEngine) : Command(inputEngine) {}

/// @brief 
/// Execute function for moveRight
void MoveRight::execute()
{
	inputEngine->moveRight();
}

Jump::Jump(InputEngine* _inputEngine) : Command(inputEngine) {}

/// @brief 
/// Execute function for jumping
void Jump::execute()
{
	inputEngine->jump();
}

ToggleFps::ToggleFps(InputEngine* _inputEngine) : Command(inputEngine) {}

/// @brief
///  Execute function for toggling fps
void ToggleFps::execute() {
	inputEngine->toggleFps();
}