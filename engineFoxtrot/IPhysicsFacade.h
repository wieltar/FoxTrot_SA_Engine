#pragma once

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"

#if(EXPORT)
class DLLEXPORT IPhysicsFacade
#else
class IPhysicsFacade
#endif
{
public:
	IPhysicsFacade();
	~IPhysicsFacade();

private:

};




