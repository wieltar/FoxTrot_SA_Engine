#include "stdafx.h"
#include "SVI.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include "../../SDL2/include/SDL_mixer.h"
#include "../../SDL2/include/SDL_image.h"
#undef main
// Tips:
// http://lazyfoo.net/tutorials/SDL/07_texture_loading_and_rendering/index.php
/// @brief 
/// Inits SDL2
void SVI::initSDL()
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
void SVI::clearScreen()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
}

/// @brief 
/// Draws SDL screen
void SVI::drawScreen()
{
	SDL_RenderPresent(renderer);
}
/// @brief 
/// Load a animated sprite into the AnimatedTexture map
/// @param spriteID 
/// @param filename
/// @param height of 1 single animation sprite
/// @param widht of 1 single animation sprite
/// @param amount of animations of 1 sprite
void SVI::loadSprite(int spriteID, const char* filename, int singleSpriteHeight, int singleSpriteWidth, int size) {
	if (spriteID == NULL) throw ERROR_CODE_SVIFACADE_LOADIMAGE_SPRITE_ID_IS_NULL;
	if (filename == NULL) throw ERROR_CODE_SVIFACADE_FILENAME_IS_NULL;

	SDL_Surface* surface = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SpriteObject* spriteObject = new SpriteObject(spriteID, size, singleSpriteHeight, singleSpriteWidth);
	textureMap[spriteID] = texture;
	animatedTextureMap[spriteID] = spriteObject;
	SDL_FreeSurface(surface);
}

/// @brief 
	/// Takes the sprites from the Textuture map animated and copys them to the screen
	/// @param object 
void SVI::renderCopy(Object& object)
{
	// TODO
	//if (textureMap[spriteID] == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_SPRITE_ID_IS_NULL;
	//if (xPos == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_XPOS_IS_NULL;
	//if (yPos == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_YPOS_IS_NULL;
	//if (height == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_HEIGHT_IS_NULL;
	//if (width == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_WIDTH_IS_NULL;
	//if (rotation == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_ROTATION_IS_NULL;
	// TODO find out why floats ruin stuff
	SDL_Rect destination;
	destination.x = object.getPositionX();
	destination.y = object.getPositionY() - object.getHeight();
	destination.w = object.getWidth();
	destination.h = object.getHeight();

	SpriteObject* sprite = animatedTextureMap[object.getSpriteID()];
	if (sprite == NULL) {
		//throw ERROR_CODE_SDL2FACADE_SPRITE_DOESNT_EXISTS;
	}
	Uint32 ticks = SDL_GetTicks();
	Uint32 seconds = ticks / 300;
	Uint32 pos = seconds % sprite->getAmountOfTextures();
	int leftPos = pos * sprite->getWidth();
	SDL_Rect rect{ leftPos, 0, sprite->getWidth(), sprite->getHeight() };
	SDL_RenderCopy(renderer, textureMap[object.getSpriteID()], &rect, &destination);
}
