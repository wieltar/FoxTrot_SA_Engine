#include "stdafx.h"

#include "InputFacade.h"
#include <SDL.h>

#undef main

/// @brief 
InputFacade::InputFacade() {}

/// @brief 
InputFacade::~InputFacade()
{
}

/// @brief
/// Poll the input events and dispatch a KeyPressedEvent
void InputFacade::pollEvents() {
	SDL_Event sdl_event;
	if (&sdl_event)
	{
		while (SDL_PollEvent(&sdl_event))
		{
			switch (sdl_event.type)
			{
			case SDL_KEYDOWN: {
				if(sdl_event.key.keysym.sym == SDLK_F4)
					exit(100);
				// Command queue with events to fire
				KeyPressedEvent event((KeyCode)sdl_event.key.keysym.scancode, 1);
				EventSingleton::get_instance().dispatchEvent<KeyPressedEvent>(event);
				break;
			}
			case SDL_KEYUP: {
				KeyReleasedEvent event((KeyCode)sdl_event.key.keysym.scancode);
				EventSingleton::get_instance().dispatchEvent<KeyReleasedEvent>(event);
				break;
			}
			case SDL_QUIT: {
				break;
			}
			default:
				break;
			}
		}
	}
}