#pragma once


#if(EXPORT)
enum DLLEXPORT EventCategry
#else
enum EventCategory
#endif
{
	None			= 0x01,
	MOUSE_EVENT		= 0x02,
	WINDOW_EVENT	= 0x03,
	INPUT_EVENT		= 0x04,
	ENGINE_EVENT	= 0x05
};

#if(EXPORT)
enum class EventType
#else
enum class EventType
#endif
{
	MOVE			= 0x01,
	INTERACT		= 0x02,
	INPUT			= 0x03,
	MOVE_UPDATED	= 0x04,
	COLLISION		= 0x05,
	ENGINE60		= 0x06,
	ENGINE30		= 0x07
};
