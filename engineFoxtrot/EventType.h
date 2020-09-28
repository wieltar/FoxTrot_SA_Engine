#pragma once

enum EventCategory
{
	None			= 0x01,
	MOUSE_EVENT		= 0x02,
	WINDOW_EVENT	= 0x03,
	INPUT_EVENT		= 0x04,
	ENGINE_EVENT	= 0x05
};

enum class EventType {
	MOVE			= 0x01,
	INTERACT		= 0x02,
	INPUT			= 0x03,
	MOVE_UPDATED	= 0x04,
	COLLISION		= 0x05
};
