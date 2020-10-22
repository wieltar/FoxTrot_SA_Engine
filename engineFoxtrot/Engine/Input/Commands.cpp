#include "stdafx.h"
#include "Commands.h"
#include "InputEngine.h"


void MoveRight::execute(InputEngine* inputEngine)
{
	inputEngine->moveRight();
}

void Jump::execute(InputEngine* inputEngine)
{
	inputEngine->jump();
}
