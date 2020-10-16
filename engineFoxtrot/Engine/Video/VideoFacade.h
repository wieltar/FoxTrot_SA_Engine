#pragma once

#include "IVideo.h"
#include <SDL.h>
#include <unordered_map>
#include "../../SDL2/include/SDL_image.h"
#include "../SceneManager/Object.h"
#undef main

using namespace std;

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

#if(EXPORT)
class DLLEXPORT VideoFacade : public IVideo
#else
/// @brief 
/// SVI is de SDL2 facade
class VideoFacade : public IVideo
#endif
{
public:
	VideoFacade();
	~VideoFacade();

	void initSDL();

	void clearScreen();
	void drawScreen();
	void loadImage(const int spriteID, const char* filename);
	void renderCopy(Object& object);

	unordered_map<int, SDL_Texture*> textureMap;

private:
	SDL_Renderer* renderer;
	SDL_Window* window;
};