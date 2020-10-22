#include "stdafx.h"
#include "InputFacade.h"
#include <SDL.h>

InputFacade::InputFacade()
{

}

InputFacade::~InputFacade()
{

}

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

void InputFacade::keydown(SDL_Event& event)
{
    if (state_map[event.key.keysym.sym] == RELEASED) {
        action_map[event.key.keysym.sym] = EXECUTE;
    }
    state_map[event.key.keysym.sym] = PRESSED;
}

void InputFacade::keyup(SDL_Event& event)
{
    state_map[event.key.keysym.sym] = RELEASED;
}

bool InputFacade::is_held(int key)
{
    return state_map[key];
}

bool InputFacade::was_pressed(int key)
{
    return action_map[key];
}

void InputFacade::configure(int key, Command* command)
{
    commands[key] = command;    // key points to newly assigned command
}

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
