#pragma once
#include "IVideoFacade.h"
#include "../SceneManager/Object.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

struct SDL_Renderer;
struct SDL_Window;
struct SDL_Texture;

#if(EXPORT)
class DLLEXPORT VideoFacade : public IVideoFacade
#else
/// @brief 
/// VideoFacade is de SDL2 facade
class VideoFacade : public IVideoFacade
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