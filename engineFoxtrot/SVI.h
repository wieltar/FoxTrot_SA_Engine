#pragma once

#include "ISVI.h"

#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"
#include "SDL.h"
#include "Sound.h"
#include <string>
#include <map>
#include <memory>
#include <iostream>
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

	SDL_Renderer* rendererSDL2;
	SDL_Window* windowSDL2;

private:



// Sound functions
public:
	void load(string filename, string identifier);
	void play(string identifier);
	void stop(string identifier);
	void unload(string identifier);
	void flush();
private:
	map<string, Sound> devices;


// Video functions
public:
	void testLoopVideo(int x, int y);

private:


// Input functions
public:
	void input();

private:
	int mousex = 0;
	int mousey = 0;
};



