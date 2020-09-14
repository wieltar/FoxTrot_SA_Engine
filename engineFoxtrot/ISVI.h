#pragma once

class ISVI
{
public:
	ISVI();
	~ISVI();

	// Sound Functions
	virtual void load(const char* filename) = 0;
	virtual void play() = 0;

	// Video Functions
	virtual void testLoopVideo() = 0;

	// Input Functions
	virtual void input() = 0;

private:

};
