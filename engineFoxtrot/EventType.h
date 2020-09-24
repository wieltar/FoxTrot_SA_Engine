#pragma once

enum EventCategory
{
	None = 0,
	MOUSE_EVENT,
	WINDOW_EVENT,
	INPUT_EVENT,
	ENGINE_EVENT
};

enum class EventType {
	MOVE,
	INTERACT,
	INPUT,
	MOVE_UPDATED,
	COLLISION
};
