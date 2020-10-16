#pragma once
enum class ObjectEvent
{
	Move,
	Jump
};
// teveel overeenkomend?
enum class ObjectMoveEventType {
	Left,
	Right,
	Up,
	Down,
};

// TODO
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
};
