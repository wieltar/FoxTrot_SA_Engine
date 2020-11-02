#include "stdafx.h"
#include "VideoFacade.h"

#include <SDL.h>
#include "../../SDL2/include/SDL_image.h"
#include "../../SDL2/include/SDL_ttf.h"

#undef main
#define ANIMATIONDELAY 100;

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
/// Load a animated sprite into the texturemap map
/// @param spriteObject 
/// @param filename
void VideoFacade::loadImage(const SpriteObject& spriteObject) {
	if (spriteObject.getTextureID() == NULL) throw ERROR_CODE_SVIFACADE_LOADIMAGE_SPRITE_ID_IS_NULL;
	if (spriteObject.getFileName() == NULL) throw ERROR_CODE_SVIFACADE_FILENAME_IS_NULL;

	SDL_Surface* surface = IMG_Load(spriteObject.getFileName());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	textureMap[spriteObject.getTextureID()] = texture;
	SDL_FreeSurface(surface);
}

/// @brief 
/// Takes the sprites from the Textuture map animated and copys them to the screen
/// @param object 
void VideoFacade::renderCopy(Object& object)
{	
	SpriteObject& sprite = object.GetCurrentSprite();

	if (textureMap[sprite.getTextureID()] == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_SPRITE_ID_IS_NULL;
	if (object.getPositionX() == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_XPOS_IS_NULL;
	if (object.getPositionY() == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_YPOS_IS_NULL;
	if (object.getHeight() == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_HEIGHT_IS_NULL;
	if (object.getWidth() == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_WIDTH_IS_NULL;

	//generate image 
	Uint32 ticks = SDL_GetTicks();
	Uint32 seconds = ticks / ANIMATIONDELAY;
	int leftpos = sprite.getLeftPos(seconds);
	int top = 0;

	//generate rectangele for selecting 1 image of a full sprite
	//leftpos = amount of pixels from the left side
	//top = amount of pixels of the top (sprites are renderd of the top to bottom
	//width = amount of pixels of the with of 1 image
	//height = amount of pixels of the height of 1 image
	SDL_Rect rect{ leftpos, top, sprite.getWidth(), sprite.getHeight() };

	//update collision box 
	if (!object.getScalable()) {
		object.setWidth(sprite.getWidth());
		object.setHeight(sprite.getHeight());
	}

	//generate stratch of image
	SDL_Rect destination;
	destination.x = object.getPositionX();
	destination.y = object.getPositionY() - object.getHeight();
	destination.w = object.getWidth();
	destination.h = object.getHeight();
	SDL_RenderCopyEx(renderer, textureMap[sprite.getTextureID()], &rect, &destination, object.getRotation(), NULL, SDL_FLIP_NONE);
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