#include "SVI.h"

// Functions in this cpp file may only call functions in this file. And global SDL2 definitions

/// @brief 
/// Test function for input
void SVI::input() 
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) { cout << "Quitting" << endl; }
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_ESCAPE) { cout << "SDLK_ESCAPE" << endl; }
			if (e.key.keysym.sym == SDLK_w) { cout << "w down" << endl; }
		}
		if (e.type == SDL_KEYUP) {
			if (e.key.keysym.sym == SDLK_w) { cout << "w up" << endl; }
		}
		SDL_GetMouseState(&mousex, &mousey);


	}
}