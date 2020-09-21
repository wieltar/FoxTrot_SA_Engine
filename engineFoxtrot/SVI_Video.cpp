#include "SVI.h"

// Functions in this cpp file may only call functions in this file. And global SDL2 definitions

// Tips:
// http://lazyfoo.net/tutorials/SDL/07_texture_loading_and_rendering/index.php

void SVI::testLoopVideo(int x, int y)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	SDL_RenderClear(renderer);
	SDL_Surface* surface = IMG_Load(Example_Sprite);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	
	SDL_Rect destination;
	destination.x = x;
	destination.y = y;
	destination.w = 320;
	destination.h = 320;
	SDL_FreeSurface(surface);

	SDL_RenderCopy(renderer, texture, NULL, &destination);

	SDL_RenderPresent(renderer);

	//SDL_Delay(5000);
}

void SVI::initSDL()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Foxtrot Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create renderer for window
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Initialize renderer color
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			}
		}
	}
}

void SVI::clearScreen()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
}

void SVI::updateScreen()
{
	SDL_RenderPresent(renderer);
}

void SVI::loadImage(int spriteID, const char* filename)
{
	SDL_Surface* surface = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	textureMap[spriteID] = texture;
}


void SVI::renderCopy(int spriteID, int xPos, int yPos, int width, int height)
{
	SDL_Rect destination;
	destination.x = xPos;
	destination.y = yPos;
	destination.w = width;
	destination.h = height;
	SDL_RenderCopy(renderer, textureMap[spriteID], NULL, &destination);
}


