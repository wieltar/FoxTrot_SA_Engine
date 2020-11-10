#pragma once
#include "Events/Event.h"

/// @brief
/// KeyEvent base class for all key events:
/// Keypressed, KeyReleased, KeyTyped
class BaseSoundEvent : public Event
{
public:
	/// @brief
	/// KeyCode that is pressed
	/// @returns KeyCode
	const std::string& Getidentifier() { return identifier; }


protected:
	BaseSoundEvent(const std::string& identifier) : identifier{ identifier } {};
	const std::string& identifier;
};
