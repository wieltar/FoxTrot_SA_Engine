#pragma once

#ifndef IVIDEOFACADE__H
#define IVIDEOFACADE__H

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"


class IVideoFacade
{
public:
	IVideoFacade();
	virtual ~IVideoFacade();

	virtual void testLoopFacade() = 0;
private:

};






#endif

