#pragma once
#include "GroundData.h"

class ISVI
{
public:
	ISVI();
	~ISVI();

	// Sound Functions
	virtual void load(const char* filename) = 0;
	virtual void play() = 0;

	// Video Functions
	virtual void testLoopVideo(GroundData box, GroundData g) = 0;

	// Input Functions
	virtual void input() = 0;

private:

};
