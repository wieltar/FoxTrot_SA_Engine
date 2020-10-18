#pragma once

enum InputType
{
    ACTION,
    STATE,
    RANGE
};

enum ActionType
{
    EXECUTE = true,
    STOP = false
};

enum State
{
    PRESSED = true,
    RELEASED = false
};
