#include "stdafx.h"
#include "VideoFacade.h"

#include <SDL.h>
#include "../../SDL2/include/SDL_image.h"
#include "../../SDL2/include/SDL_ttf.h"

#undef main

/// @brief 
VideoFacade::VideoFacade()
{
	initSDL();
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
	TTF_Init();
	Sans = TTF_OpenFont(FONT_PATH, FONT_POINT_SIZE);
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
	try {
		SDL_RenderPresent(renderer);
	}
	catch (...) {
		std::cout << "ERR" << std::endl;
	}
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

/// @brief
/// Draws the given text message at the given position
/// @param message
/// A Message struct containing the message and the color of the message
/// @param pos
/// A Position struct containing the position to draw the message at
void VideoFacade::drawMessageAt(const FpsMessage message, const TextPosition pos)
{
	bool exists = std::filesystem::exists(FONT_PATH); // TODO dynamic fonts

	if (exists) {

		SDL_Color Color = { message.red, message.green, message.blue };
		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, message.text.c_str(), Color);
		SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

		SDL_Rect Message_rect;

		// If the message doesn't fit the screen, make it fit the screen
		int xPos = pos.xPos + MESSAGE_WIDTH > WINDOW_WIDTH ? WINDOW_WIDTH - MESSAGE_WIDTH : pos.xPos < 0 ? 0 : pos.xPos;
		int yPos = pos.yPos + MESSAGE_HEIGHT > WINDOW_HEIGHT ? WINDOW_HEIGHT - MESSAGE_HEIGHT : pos.yPos < 0 ? 0 : pos.yPos;

		Message_rect.x = xPos;
		Message_rect.y = yPos;
		Message_rect.w = MESSAGE_WIDTH;
		Message_rect.h = MESSAGE_HEIGHT;

		SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);
	}
}