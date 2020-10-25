#pragma once
#include "./VideoFacade.h"

#if(EXPORT)
struct DLLEXPORT Sprite
#else
struct Sprite
#endif
{
	int spriteID = 0;
	const char* filename = "";
};

/// @brief 
/// Video is the SDL2 wrapper

#if(EXPORT)
class DLLEXPORT VideoEngine
#else
class VideoEngine
#endif
{
public:
	VideoEngine();
	~VideoEngine();

	//void initSDL();

	void clearScreen();
	void drawScreen();
	void loadImage(const int spriteID, const char* filename);

	void renderCopy(Object& object);

	void updateScreen();

	void update(Object* object);
	void receiveTick(Event& tickEvent);

	vector <Object*>* pointerToObjectVector = nullptr;

private:
	IVideoFacade* videoFacade = new VideoFacade;
};
