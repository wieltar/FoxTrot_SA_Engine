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
	const std::string& GetFileName() { return fileName; }


protected:
	BaseSoundEvent(const std::string& _fileName) : fileName{ _fileName } {};
	const std::string& fileName;
};
