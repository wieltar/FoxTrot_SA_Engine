#include "SVI.h"


SVI::SVI() 
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(360, 240, 0, &win, &ren);
}

SVI::~SVI()
{
	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);
}