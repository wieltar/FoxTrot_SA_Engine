#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <unordered_map>
#include "Glitch/Renderer/WindowProps.h"

namespace Glitch {
	class GLITCH_API SDL2Facade
	{
	public:
		SDL2Facade() {
			Init();
		}
		~SDL2Facade() {};

		void createWindow(WindowProps* props);

		void createRenderer();
		void clearScreen();
		void drawScreen();
		void loadImage(int spriteID, const char* filename);
		void renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation);

		void deallocateSurface();
		SDL_Window* getWindow() { return window; }

		void Init();
		void destroyScreen();
	private:

		SDL_Window* window;
		SDL_Surface* screenSurface;
		SDL_Renderer* renderer;
		unordered_map<int, SDL_Texture*> textureMap;
	};
}

