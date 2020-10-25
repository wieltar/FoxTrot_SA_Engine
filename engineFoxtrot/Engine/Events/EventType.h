#pragma once
/// @brief
/// EventType enum all the derived event types that can be fired as an enum
enum class EventType
{
	None = 0,
	// -- engine events -----
	Engine30, 
	Engine60,
	// -- window events -----
	WindowClose, 
	WindowResize, 
	WindowFocus, 
	WindowLostFocus, 
	WindowMoved,
	// -- key events -----
	KeyPressed, 
	KeyReleased, 
	KeyTyped,
	// -- mouse events -----
	MouseScrolled,
	MouseButtonPressed, 
	MouseButtonReleased, 
	MouseMoved, 

	Action
};
