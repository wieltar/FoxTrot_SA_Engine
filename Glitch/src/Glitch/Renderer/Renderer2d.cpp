#include "glpch.h"
#include "Renderer2d.h"

namespace Glitch {

	/// @brief 
	/// Inits SDL2 renderer on window
	void Renderer2d::Init()
	{
		//Create renderer for window -- kan naar facade
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		if (renderer == NULL)
		{
			GL_CORE_ERROR("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			throw ERROR_CODE_SVIFACADE_CANT_CREATE_RENDERER;
		}

		screenSurface = SDL_GetWindowSurface(window); // ?

		//Initialize PNG loading -- kan naar facade
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			GL_CORE_ERROR("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		}

	}

	void Renderer2d::OnUpdate()
	{
		clearScreen();
		drawScreen();
		// TODO draw object vector
	}

	void Renderer2d::Shutdown()
	{
		//Deallocate surface
		// roept facade aan voor shutdown van renderer functies via interface
		SDL_FreeSurface(screenSurface);
		screenSurface = NULL;
	}

	/// @brief 
	/// Clears SDL screen
	void Renderer2d::clearScreen()
	{
		// set draw color -> facade etc.
		SDL_SetRenderDrawColor(renderer, 2, 200, 80, 6);
		SDL_RenderClear(renderer);
	}

	/// @brief 
	/// Draws SDL screen
	void Renderer2d::drawScreen()
	{
		SDL_RenderPresent(renderer);
	}

	/// @brief 
	/// Loads PNG files and makes them textures to be added to the unordered map
	/// @param spriteID 
	/// @param filename 
	void Renderer2d::loadImage(int spriteID, const char* filename)
	{
		if (spriteID == NULL) throw ERROR_CODE_SVIFACADE_LOADIMAGE_SPRITE_ID_IS_NULL;
		if (filename == NULL) throw ERROR_CODE_SVIFACADE_FILENAME_IS_NULL;
		// naar facade
		SDL_Surface* surface = IMG_Load(filename);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		textureMap[spriteID] = texture;
		// ----
	}

	/// @brief 
	/// Takes the sprites from the Textuture map and copys them to the screen
	/// @param spriteID 
	/// @param xPos 
	/// @param yPos 
	/// @param width 
	/// @param height 
	/// @param rotation 
	void Renderer2d::renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation)
	{
		// TODO
		//if (textureMap[spriteID] == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_SPRITE_ID_IS_NULL;
		//if (xPos == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_XPOS_IS_NULL;
		//if (yPos == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_YPOS_IS_NULL;
		//if (height == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_HEIGHT_IS_NULL;
		//if (width == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_WIDTH_IS_NULL;
		//if (rotation == NULL) throw ERROR_CODE_SVIFACADE_RENDERCOPY_ROTATION_IS_NULL;

		SDL_Rect destination;
		destination.x = xPos;
		destination.y = yPos;
		destination.w = width;
		destination.h = height;
		SDL_RenderCopyEx(renderer, textureMap[spriteID], NULL, &destination, rotation, NULL, SDL_FLIP_NONE);
	}


}