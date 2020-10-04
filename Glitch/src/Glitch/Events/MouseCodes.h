#pragma once
#include "SDL_mouse.h"
namespace Glitch
{
	using MouseCode = Uint8;

	namespace Mouse
	{
		enum : MouseCode
		{
			MOUSE_BTN_LEFT = SDL_BUTTON_LEFT, 
			MOUSE_BTN_MIDDLE = SDL_BUTTON_MIDDLE,
			MOUSE_BTN_RIGHT = SDL_BUTTON_RIGHT,
			MOUSE_BTN_1 = SDL_BUTTON_X1,
			MOUSE_BTN_2 = SDL_BUTTON_X2,
		};
	}
}