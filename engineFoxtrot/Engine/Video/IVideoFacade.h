#pragma once
#include "../SceneManager/Object.h"
#include "./Structs/fpsStructs.h"

/// @brief Interface class for Video facade
class IVideoFacade
{
public:
	IVideoFacade() {};
	~IVideoFacade() {};

	virtual void initSDL() = 0;
	virtual void clearScreen() = 0;
	virtual void drawScreen() = 0;
	virtual void loadImage(const int spriteID, const char* filename) = 0;
	virtual void renderCopy(Object& object) = 0;
	virtual void drawMessageAt(const FpsMessage message, const TextPosition pos) = 0;


private:

};
