#pragma once
#include "../SceneManager/Object.h"

/// @brief Interface class for Video facade
#if(EXPORT)
class DLLEXPORT IVideoFacade
#else
class IVideoFacade
#endif
{
public:
	IVideoFacade() {};
	~IVideoFacade() {};

	virtual void initSDL() = 0;
	virtual void clearScreen() = 0;
	virtual void drawScreen() = 0;
	virtual void loadImage(const int spriteID, const char* filename) = 0;
	virtual void renderCopy(Object& object) = 0;

private:

};