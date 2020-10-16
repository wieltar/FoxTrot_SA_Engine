#include "stdafx.h"
#include "VideoFacade.h"

#include <SDL.h>
#include "../../SDL2/include/SDL_image.h"

#undef main

/// @brief 
VideoFacade::VideoFacade()
{
	initSDL();

	SDL_Init(SDL_INIT_EVERYTHING);
}

/// @brief 
VideoFacade::~VideoFacade()
{

}

// Tips:
// http://lazyfoo.net/tutorials/SDL/07_texture_loading_and_rendering/index.php
/// @brief 
/// Inits SDL2
void VideoFacade::initSDL()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Foxtrot Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{

		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		throw ERROR_CODE_SVIFACADE_CANT_CREATE_WINDOW;
	}
	else
	{
		//Create renderer for window
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			throw ERROR_CODE_SVIFACADE_CANT_CREATE_RENDERER;
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

/// @brief 
/// Clears SDL screen
void VideoFacade::clearScreen()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
}

/// @brief 
/// Draws SDL screen
void VideoFacade::drawScreen()
{
	SDL_RenderPresent(renderer);
}

/// @brief 
/// Loads PNG files and makes them textures to be added to the unordered map
/// @param spriteID 
/// @param filename 
void VideoFacade::loadImage(const int spriteID, const char* filename)
{
	if (spriteID == NULL) throw ERROR_CODE_SVIFACADE_LOADIMAGE_SPRITE_ID_IS_NULL;
	if (filename == NULL) throw ERROR_CODE_SVIFACADE_FILENAME_IS_NULL;
	SDL_Surface* surface = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	textureMap[spriteID] = texture;
}


/// @brief 
/// Takes the sprites from the Textuture map and copys them to the screen
/// @param Object 
void VideoFacade::renderCopy(Object& object)
{
	SDL_Rect destination;
	destination.w = object.getWidth();
	destination.h = object.getHeight();
	destination.x = object.getPositionX();
	destination.y = object.getPositionY() - object.getHeight();

	SDL_RenderCopyEx(renderer, textureMap[object.getSpriteID()], NULL, &destination, object.getRotation(), NULL, SDL_FLIP_NONE);
}
