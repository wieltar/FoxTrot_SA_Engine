#pragma once
#include "SVI.h"

class SVIEngine
{
public:
	SVIEngine();
	~SVIEngine();
	
	// Video Functions
	void testLoopVideo(int x, int y);

	// Input Functions
	void input();


	//Set to private after testing!!!
	ISVI * sviEngine = new SVI;
private:
};
