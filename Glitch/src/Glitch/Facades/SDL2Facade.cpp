#include "glpch.h"
#include "SDL2Facade.h"

namespace Glitch {

	/// @brief 
	/// Inits SDL2 renderer on window
	void SDL2Facade::Init()
	{
		
	}

	void SDL2Facade::destroyScreen() {
		// Close and destroy the window
		SDL_DestroyWindow(window);
		window = NULL;

		// Clean up
		SDL_Quit();
	}

	void SDL2Facade::deallocateSurface()
	{
		//Deallocate surface
		SDL_FreeSurface(screenSurface);
		screenSurface = NULL;
	}

	/// @brief 
	/// Takes the sprites from the Textuture map and copys them to the screen
	/// @param spriteID 
	/// @param xPos 
	/// @param yPos 
	/// @param width 
	/// @param height 
	/// @param rotation 
	void SDL2Facade::renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation)
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

	void SDL2Facade::loadImage(int spriteID, const char* filename)
	{
		if (spriteID == NULL) throw ERROR_CODE_SVIFACADE_LOADIMAGE_SPRITE_ID_IS_NULL;
		if (filename == NULL) throw ERROR_CODE_SVIFACADE_FILENAME_IS_NULL;
		// naar facade
		SDL_Surface* surface = IMG_Load(filename);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		textureMap[spriteID] = texture;
		// ----
	}

	void SDL2Facade::createWindow(WindowProps* m_data)
	{
		// Initialize SDL2
	
		int success = SDL_Init(SDL_INIT_VIDEO);
		const char* err = SDL_GetError();

		//GL_CORE_ASSERT(success, "Could not initialize SDL2 Error: {0}");
		
		window = SDL_CreateWindow(
			m_data->Title,			// window title
			SDL_WINDOWPOS_CENTERED,	// initial x position
			SDL_WINDOWPOS_CENTERED,	// initial y position
			m_data->Width,			// width, in pixels
			m_data->Height,			// height, in pixels
			0
		);

		if (window == NULL)
		{
			GL_CORE_ERROR("Window could not be created! SDL Error: %s\n", SDL_GetError());
			throw ERROR_CODE_SVIFACADE_CANT_CREATE_WINDOW;
		}

		// set the window id in the window props struct
		m_data->Id = SDL_GetWindowID(window);
		SDL_SetWindowData(window, m_data->Title, m_data);
	}

	void SDL2Facade::createRenderer()
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

	/// @brief 
	/// Clears SDL screen
	void SDL2Facade::clearScreen()
	{
		// set draw color -> facade etc.
		SDL_SetRenderDrawColor(renderer, 2, 200, 80, 6);
		SDL_RenderClear(renderer);
	}

	/// @brief 
	/// Draws SDL screen
	void SDL2Facade::drawScreen()
	{
		SDL_RenderPresent(renderer);
	}
}