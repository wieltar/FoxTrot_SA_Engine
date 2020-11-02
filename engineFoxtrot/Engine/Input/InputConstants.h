#pragma once
#include "core.h"
/// @brief 
/// Type of button input
enum class InputType
{
    ACTION,
    STATE,
    RANGE
};

/// @brief 
/// Type of button action
enum class Action
{
    EXECUTE = true,
    STOP = false
};

/// @brief 
/// Button state
enum class State
{
    PRESSED = true,
    RELEASED = false
};
