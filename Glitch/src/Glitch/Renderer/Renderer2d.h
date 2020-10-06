#pragma once
#include <glpch.cpp>
#include <Glitch\Core\Object.h>
#include "SDL.h"
#include "SDL_image.h"
#include "Glitch/ISystem.h"
#include <Glitch\Renderer\window.h>

namespace Glitch {
	class GLITCH_API Renderer2d : public ISystem
	{
	public:
		Renderer2d(const WindowProps* wData) :
			windowData{ wData }
		{
			if (wData == nullptr)
			{
				GL_ERROR("Cannot initialise renderer without a window");
				// TODO throw exception
			}

			// TODO ?
			window = SDL_GetWindowFromID(windowData->Id);

			Init();
		}
		~Renderer2d() {};

		vector <Object*>* pointerToObjectVector = nullptr;
		void clearScreen();
		void drawScreen();
		void loadImage(int spriteID, const char* filename);
		void renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation);

		// Inherited via ISystem
		virtual void OnUpdate() override;
		virtual void Shutdown() override;

	private:
		virtual void Init();
		const WindowProps* windowData;
		SDL_Window* window;
		SDL_Surface* screenSurface;
		SDL_Renderer* renderer;
		unordered_map<int, SDL_Texture*> textureMap;


	};

}

