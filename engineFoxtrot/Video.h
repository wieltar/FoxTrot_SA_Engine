#pragma once

#ifndef VIDEO__H
#define VIDEO__H

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"
#include "VideoFacade.h"

class Video
{
public:
	Video();
	~Video();

	void testLoop();

	//Set to private after testing
public:
	IVideoFacade * videoFacade = new VideoFacade;
private:

};



#endif

