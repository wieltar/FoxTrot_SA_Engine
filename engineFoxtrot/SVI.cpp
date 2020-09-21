#include "SVI.h"


SVI::SVI() 
{
	initSDL();
}

SVI::~SVI()
{
	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);
}