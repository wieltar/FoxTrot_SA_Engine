#include "SVI.h"

// Functions in this cpp file may only call functions in this file. And global SDL2 definitions

// Tips:
// http://lazyfoo.net/tutorials/SDL/07_texture_loading_and_rendering/index.php

void SVI::testLoopVideo()
{
	SDL_SetRenderDrawColor(rendererSDL2, 0, 0, 255, 255);

	SDL_RenderClear(rendererSDL2);
	SDL_Surface* surface = IMG_Load(Example_Sprite);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(rendererSDL2, surface);
	

	SDL_Rect destination;
	destination.x = 0;
	destination.y = 0;
	destination.w = surface->w;
	destination.h = surface->h;
	SDL_FreeSurface(surface);

	SDL_RenderCopy(rendererSDL2, texture, NULL, &destination);

	SDL_RenderPresent(rendererSDL2);

	//SDL_Delay(5000);
}

