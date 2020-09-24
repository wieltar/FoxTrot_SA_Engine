#pragma once
#include <functional>
class ISVI
{
public:
	ISVI();
	~ISVI();

	// Sound Functions
	virtual void load(const char* filename) = 0;
	virtual void play() = 0;

	// Video Functions
	virtual void testLoopVideo(int x, int y) = 0;

	// Input Functions
	virtual void RegisterCommand(std::function<void> callback, int inputType, int key, int mouseBtn) = 0;
	virtual void InputHandle() = 0;
private:

};
