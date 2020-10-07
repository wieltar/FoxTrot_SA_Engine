#pragma once

namespace Glitch {
	class ISDL2Facade
	{
	public:
		ISDL2Facade() {};
		~ISDL2Facade() {};

		virtual void createWindow(WindowProps* props) = 0;
		virtual void createRenderer() = 0;
		virtual void clearScreen() = 0;
		virtual void drawScreen() = 0;
		virtual void loadImage(int spriteID, const char* filename) = 0;
		virtual void renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation) = 0;
		virtual void deallocateSurface() = 0;
		virtual void Init() = 0;
		virtual void destroyScreen() = 0;
		virtual SDL_Window* getWindow() = 0;


	private:

	};

}