#include "SVI.h"

// Functions in this cpp file may only call functions in this file. And global SDL2 definitions


void SVI::testLoopVideo()
{
	SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);

	SDL_RenderClear(ren);

	SDL_RenderPresent(ren);

	SDL_Delay(5000);
}