#pragma once

/// @brief 
/// Type of button input
enum InputType
{
    ACTION,
    STATE,
    RANGE
};

/// @brief 
/// Type of button action
enum Action
{
    EXECUTE = true,
    STOP = false
};

/// @brief 
/// Button state
enum State
{
    PRESSED = true,
    RELEASED = false
};
