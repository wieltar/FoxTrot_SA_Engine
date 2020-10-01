#pragma once

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

class IPhysicsFacade
{
public:
	IPhysicsFacade();
	~IPhysicsFacade();


	void MoveLeft(int objectId);
	void MoveRight(int objectId);
	void Jump(int objectId);
	void JumpLeft(int objectId);
	void JumpRight(int objectId);
private:

};




