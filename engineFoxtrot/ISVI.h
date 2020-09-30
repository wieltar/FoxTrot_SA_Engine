#pragma once
#include <string>

class ISVI
{
public:
	ISVI();
	~ISVI();

	// Sound Functions
	virtual void load(std::string filename, std::string identifier) = 0;
	virtual void play(std::string identifier) = 0;
	virtual void stop(std::string identifier) = 0;
	virtual void unload(std::string identifier) = 0;
	virtual void flush() = 0;

	// Video Functions
	virtual void testLoopVideo(int x, int y) = 0;

	// Input Functions
	virtual void input() = 0;

private:

};
