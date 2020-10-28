#pragma once
#include "core.h"
/// @brief 
/// Type of button input
enum API InputType
{
    ACTION,
    STATE,
    RANGE
};

/// @brief 
/// Type of button action
enum API Action
{
    EXECUTE = true,
    STOP = false
};

/// @brief 
/// Button state
enum API State
{
    PRESSED = true,
    RELEASED = false
};
