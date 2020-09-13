#include "SVI.h"


SVI::SVI() 
{

	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("Foxtrot Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	ren = SDL_CreateRenderer(win, -1, 0);
}

SVI::~SVI()
{
	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);
}