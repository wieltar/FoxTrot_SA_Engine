#include "SVI.h"

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
/// Loads PNG files and makes them textures to be added to the unordered map
/// @param spriteID 
/// @param filename 
void SVI::loadImage(const int spriteID, const char* filename)
{
	if (spriteID == NULL) throw ERROR_CODE_SVIFACADE_LOADIMAGE_SPRITE_ID_IS_NULL;
	if (filename == NULL) throw ERROR_CODE_SVIFACADE_FILENAME_IS_NULL;
	SDL_Surface* surface = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	textureMap[spriteID] = texture;
}


/// @brief 
/// Test function used for POC
/// @param spriteID 
/// @param xPos 
/// @param yPos 
/// @param width 
/// @param height 
/// @param rotation 
void SVI::renderCopy(const int spriteID, const int xPos, const int yPos, const int width, const int height, const int rotation)
{
	SDL_Rect destination;
	destination.x = xPos;
	destination.y = yPos - height;
	destination.w = width;
	destination.h = height;

	SDL_RenderCopyEx(renderer, textureMap[spriteID], NULL, &destination, rotation,NULL, SDL_FLIP_NONE);
}

/// @brief 
/// Takes the sprites from the Textuture map and copys them to the screen
/// @param Object 
void SVI::renderCopy(Object& object)
{
	SDL_Rect destination;
	destination.w = object.getWidth();
	destination.h = object.getHeight();
	destination.x = object.getPositionX();
	destination.y = object.getPositionY() - object.getHeight();

	SDL_RenderCopyEx(renderer, textureMap[object.getSpriteID()], NULL, &destination, object.getRotation(), NULL, SDL_FLIP_NONE);
}
