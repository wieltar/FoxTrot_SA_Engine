#include "stdafx.h"

#include "InputFacade.h"
#include <SDL.h>

#undef main

/// @brief 
InputFacade::InputFacade()
{

}

/// @brief 
InputFacade::~InputFacade()
{

}

/// @brief 
/// Checks if any keys are pressed and will call keydown or keyup function
/// @return 
/// Returns true poll events should quit, default false if none.
bool InputFacade::input_mapping()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
        if (event.type == SDL_QUIT) return true;
        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) return true;
            keydown(event);
        }
        else if (event.type == SDL_KEYUP) {
            keyup(event);
        }

    return false;
}

/// @brief 
/// Handles Keydown event from sdl2
/// @param event 
void InputFacade::keydown(SDL_Event& event)
{
    //int SDLInt = (int)(event.key.keysym.scancode);
    if (state_map[eventToKeyCode(event)] == State::RELEASED) {
        action_map[eventToKeyCode(event)] = Action::EXECUTE;
    }
    state_map[eventToKeyCode(event)] = State::PRESSED;
}

/// @brief 
/// Handles keyup event from sdl2
/// @param event 
void InputFacade::keyup(SDL_Event& event)
{
    state_map[eventToKeyCode(event)] = State::RELEASED;
}
/// @brief 
/// Checks if the key is currently pressed down, then the key will be in state_map
/// @param key 
/// @return 
State InputFacade::is_held(KeyCode key)
{
    return state_map[key];
}

/// @brief 
/// Checks if a key was pressed, then the key will be in action_map
/// @param key 
/// @return 
Action InputFacade::was_pressed(KeyCode key)
{
    return action_map[key];
}

/// @brief 
/// Function to convert event scancode to KeyCode
/// @param event 
/// @return KeyCode
KeyCode InputFacade::eventToKeyCode(SDL_Event& event)
{
    return KeyCode((int)(event.key.keysym.scancode));
}

/// @brief 
/// Configures the key to a command. 
/// @param key 
/// @param command 
void InputFacade::configure(KeyCode key, Command* command)
{
    commands[key] = command;    // key points to newly assigned command
}

/// @brief 
/// Fills the command queue with the dispatcher if a key is pressed
/// @param command_queue 
/// @return 
bool InputFacade::fill(vector<Command*>& command_queue)
{
    bool exit = input_mapping();    // converts raw input datum to an action and/or state

    if (exit) return true;
    else {
        dispatcher(command_queue);  // fills command queue
        action_map.clear();         // clears key presses
        return false;
    }
}

/// @brief 
/// Fills the command queue with pressed keys.
/// @param command_queue 
void InputFacade::dispatcher(std::vector<Command*>& command_queue)
{
    std::map<KeyCode, Command*>::iterator iter;
    for (iter = commands.begin(); iter != commands.end(); iter++) {
        // TODO remove the check on iter->second because types are now enforced by enum class?
        if (is_held(iter->first) == State::PRESSED && iter->second->get_input_type() == InputType::STATE)
            command_queue.push_back(iter->second);
        else if (was_pressed(iter->first) == Action::EXECUTE && iter->second->get_input_type() == InputType::ACTION)
            command_queue.push_back(iter->second);
    }
}
