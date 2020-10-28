#pragma once
#include "./VideoFacade.h"
#include "../Fps/FrameData.h"
#include "./Structs/fpsStructs.h"
#include "SceneManager/Scene.h"

#define NO_RED 0
#define NO_BLUE 0
#define NO_GREEN 0

#define FPS_X_POSITION 999
#define Y_POSITION_TOP_OF_SCREEN 0
#define FPS_Y_POSITION_OFFSET 36

struct API Sprite
{
	int spriteID = 0;
	const char* filename = "";
};

/// @brief 
/// Video is the SDL2 wrapper

class API VideoEngine
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

	void drawFps();
	void drawFps(double fps, int xPos, int yPos, const string& prefix);
	void toggleFps(); //TODO Toggle via input/Command pattern

	void update(Object* object);
	void receiveTick(Event& tickEvent);

	Scene** pointerToCurrentScene = nullptr;

private:
	IVideoFacade* videoFacade = new VideoFacade;

	FrameData* frameData = nullptr;
	bool shouldDrawFps = true; //TODO Should be set to false when toggle via button is added, see Todo above.

};
