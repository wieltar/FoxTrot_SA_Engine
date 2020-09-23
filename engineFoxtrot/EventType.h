#pragma once
#include <functional>

#define EVENT_CLASS_TYPE(type) static MEventType GetStaticType() { return MEventType::type; }\
								virtual MEventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }



enum class KeyCode : uint16_t {
	UP = 119,

	/*a = 97, b = 98, c = 99, d = 100, e = 101,
	f = 102, g = 103, h = 104, i = 105, j = 106, k = 107,
	l = 108, m = 109, n = 110, o = 111, p = 112, q = 113,
	r = 114, s = 115, t = 116, u = 117, v = 118,
	w = 119, x = 120, y = 121, z = 122*/
};

enum EventCategory
{
	None = 0,
	MOUSE_EVENT,
	WINDOW_EVENT,
	INPUT_EVENT,
	ENGINE_EVENT
};

enum class EventType {
	KEYBOARD_UP,
	KEYBOARD_LEFT,

	MOVE,
	INTERACT,
	INPUT,
	MOVE_UPDATED,
	COLLISION
};
