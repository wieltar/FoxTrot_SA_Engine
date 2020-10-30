#pragma once
#include "Events/Event.h"
#include <Events\Codes\KeyCodes.h>

/// @brief
/// KeyEvent base class for all key events:
/// Keypressed, KeyReleased, KeyTyped
class KeyEvent : public Event
{
public:
	/// @brief
	/// KeyCode that is pressed
	/// @returns KeyCode
	KeyCode GetKeyCode() const { return keycode; }

	virtual const char* GetName() const override { return "keyPressed event"; };

	/// @brief
	/// Returns the name of the event
	virtual std::string ToString() const { return GetName(); }

	EventType GetEventType() const override { return EventType::KeyPressed; }
protected:
	KeyEvent(const KeyCode _keyCode) : keycode{ _keyCode } {};
	KeyCode keycode;
};
