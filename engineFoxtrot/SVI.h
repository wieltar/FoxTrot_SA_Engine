#pragma once

#include "ISVI.h"

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"
#include "SDL.h"
#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>
#include "../SDL2/include/SDL_mixer.h"
#include "../SDL2/include/SDL.h"
#include "../SDL2/include/SDL_image.h"
#undef main

using namespace std;

#define Example_Sound	"../Assets/Sound/b423b42.wav"
#define Example_Sprite  "../Assets/Sprites/simple.png"

class SVI : public ISVI
{
// General stuff
public:
	SVI();
	~SVI();


private:
	SDL_Renderer* renderer;
	SDL_Window* window;



// Sound functions
public:
	void load(const char* filename);
	void play();
private:
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;
	SDL_AudioDeviceID deviceId;


// Video functions
public:
	void testLoopVideo(int x, int y);

	void initSDL();

	void clearScreen();
	void drawScreen();
	void loadImage(int spriteID, const char* filename);

	void renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation);


	unordered_map<int, SDL_Texture*> textureMap;

private:


// Input functions
public:
	void input();

private:
	int mousex = 0;
	int mousey = 0;
};



