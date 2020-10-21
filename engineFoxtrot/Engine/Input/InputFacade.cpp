#include "stdafx.h"
#include "InputFacade.h"
#include <SDL.h>

InputFacade::InputFacade()
{

}

InputFacade::~InputFacade()
{

}

void InputFacade::input()
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
