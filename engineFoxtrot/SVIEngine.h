#pragma once
#include "SVI.h"

class SVIEngine
{
public:
	SVIEngine();
	~SVIEngine();
	
	// Sound Functions
	void load(string filename, string identifier);
	void play(string identifier);
	void stop(string identifier);
	void unload(string identifier);
	void flush();

	// Video Functions
	void testLoopVideo(int x, int y);

	// Input Functions
	void input();


	//Set to private after testing!!!
	ISVI * sviEngine = new SVI;
private:
};
