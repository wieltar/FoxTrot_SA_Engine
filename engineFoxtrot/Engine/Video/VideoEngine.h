#pragma once
#include "./VideoFacade.h"
#include "../Fps/FrameData.h"
#include "./Structs/structs.h"

#define NO_RED 0
#define NO_BLUE 0
#define NO_GREEN 0

#define FPS_X 999
#define Y_ZERO 0
#define SDL_FPS_Y 36

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

	void initSDL();

	void clearScreen();
	void drawScreen();
	void loadImage(const int spriteID, const char* filename);

	void renderCopy(Object& object);

	void updateScreen();

	void drawFps();
	void drawFps(double fps, int xPos, int yPos, const string& prefix);
	void toggleFps(); //TODO Toggle via input/Command pattern

	void update(Object* object);
	void receiveTick(Event& tickEvent);

	vector <Object*>* pointerToObjectVector = nullptr;

	FrameData* frameData = nullptr;
private:
	IVideoFacade* videoFacade = new VideoFacade;

	bool shouldDrawFps = true; //TODO Should be set to false when toggle via button is added, see Todo above.
};
