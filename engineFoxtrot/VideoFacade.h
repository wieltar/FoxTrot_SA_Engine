#pragma once

#ifndef VIDEOFACADE__H
#define VIDEOFACADE__H

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"
#include "IVideoFacade.h"
#include <iostream>

#include "../SDL2/include/SDL.h"
#undef main
using namespace std;

class VideoFacade : public IVideoFacade
{
public:
	VideoFacade();
	~VideoFacade();

	void testLoopFacade();

private:

};




#endif
