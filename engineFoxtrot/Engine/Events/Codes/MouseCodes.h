#pragma once
// mousecodes directly reflect enum values defined in sdl without a aditional include in this file
// TODO find a suitable place for the conversion from sdl to 'our own'
using MouseCode = int;
enum MouseCode
{
	MOUSE_BTN_LEFT = 1, 
	MOUSE_BTN_MIDDLE = 2,
	MOUSE_BTN_RIGHT = 3,
	MOUSE_BTN_1 = 4,
	MOUSE_BTN_2 = 5,
};