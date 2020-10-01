#include "SVI.h"

// Functions in this cpp file may only call functions in this file. And global SDL2 definitions

// Tips:
// http://lazyfoo.net/tutorials/SDL/07_texture_loading_and_rendering/index.php

void SVI::testLoopVideo(GroundData b, GroundData g)
{
	SDL_SetRenderDrawColor(rendererSDL2, 0, 0, 255, 255);

	SDL_RenderClear(rendererSDL2);
	SDL_Surface* surface = IMG_Load(Example_Sprite);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(rendererSDL2, surface);
	




	SDL_SetRenderDrawColor(rendererSDL2, 255, 0, 0, 255); // the rect color (solid red)
	SDL_Rect rect;
	rect.x = g.x;
	rect.y = g.y;
	rect.w = g.hx;
	rect.h = g.hy;

	SDL_RenderFillRect(rendererSDL2, &rect);



	SDL_Rect destination;
	destination.x = b.x;
	destination.y = b.y;
	destination.w = b.hx;
	destination.h = b.hy;
	SDL_FreeSurface(surface);

	//SDL_RenderCopy(rendererSDL2, texture, NULL, &destination);
	SDL_SetRenderDrawColor(rendererSDL2, 0, 255, 0, 255);
	SDL_RenderFillRect(rendererSDL2, &destination);





	SDL_RenderPresent(rendererSDL2);
	//SDL_Delay(5000);
}

