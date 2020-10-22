#include "stdafx.h"
#include "InputFacade.h"
#include <SDL.h>

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
/// Returns true if a key is pressed, false if none.
bool InputFacade::input_mapping()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
        if (event.type == SDL_QUIT) return true;
        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) return true;
            keydown(event);
        }
        else if (event.type == SDL_KEYUP)
            keyup(event);

    return false;
}

/// @brief 
/// Handles Keydown event from sdl2
/// @param event 
void InputFacade::keydown(SDL_Event& event)
{
    if (state_map[event.key.keysym.sym] == RELEASED) {
        action_map[event.key.keysym.sym] = EXECUTE;
    }
    state_map[event.key.keysym.sym] = PRESSED;
}

/// @brief 
/// Handles keyup event from sdl2
/// @param event 
void InputFacade::keyup(SDL_Event& event)
{
    state_map[event.key.keysym.sym] = RELEASED;
}

/// @brief 
/// Checks if the key is currently pressed down, then the key will be in state_map
/// @param key 
/// @return 
bool InputFacade::is_held(int key)
{
    return state_map[key];
}

/// @brief 
/// Checks if a key was pressed, then the key will be in action_map
/// @param key 
/// @return 
bool InputFacade::was_pressed(int key)
{
    return action_map[key];
}

/// @brief 
/// Configures the key to a command. 
/// @param key 
/// @param command 
void InputFacade::configure(int key, Command* command)
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
    std::map<int, Command*>::iterator iter;
    for (iter = commands.begin(); iter != commands.end(); iter++) {
        if (is_held(iter->first) && iter->second->get_input_type() == STATE)
            command_queue.push_back(iter->second);
        else if (was_pressed(iter->first) && iter->second->get_input_type() == ACTION)
            command_queue.push_back(iter->second);
    }
}
