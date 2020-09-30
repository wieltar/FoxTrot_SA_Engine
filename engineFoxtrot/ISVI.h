#pragma once
#include <string>

class ISVI
{
public:
	ISVI();
	~ISVI();

	// Video Functions
	virtual void testLoopVideo(int x, int y) = 0;

	// Input Functions
	virtual void input() = 0;

private:

};
