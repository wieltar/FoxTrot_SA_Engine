#pragma once
#include "./VideoFacade.h"
#include "../Fps/FrameData.h"
#include "./Structs/fpsStructs.h"
#include "Events/Action/FpsToggleEvent.h"
#include "../SceneManager/Scene.h"
#include "../ParticleSystem/ParticleAdapter.h"


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
	void loadImage(const SpriteObject& spriteObject);

	void renderCopy(Object& object);

	void updateScreen();

	void drawFps();
	void drawFps(double fps, int xPos, int yPos, const string& prefix);
	void toggleFps(Event& fpsEvent);

	void update(Object* object);
	void receiveTick(Event& tickEvent);

	void drawParticle(ParticleAdapter* part);

	Scene** pointerToCurrentScene = nullptr;

private:
	IVideoFacade* videoFacade = new VideoFacade;

	FrameData* frameData = nullptr;
	bool shouldDrawFps = false;

};
