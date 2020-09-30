#pragma once
#include "SVI.h"

class SVIEngine
{
public:
	SVIEngine();
	~SVIEngine();
	
	// Sound Functions
	void load(const char* filename);
	void play();

	// Video Functions
	void testLoopVideo(int x, int y, GroundData g);

	// Input Functions
	void input();


	//Set to private after testing!!!
	ISVI * sviEngine = new SVI;
private:
};
