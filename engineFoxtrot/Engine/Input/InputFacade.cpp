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
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            keydown(event);
            break;

        case SDL_KEYUP:
            break;

        case SDL_QUIT:
            cout << "SDL_QUIT" << endl;
            break;

        default:
            break;
        }
    }
    return false;
}

void InputFacade::keydown(SDL_Event& event)
{
    if (commands.find(event.key.keysym.sym) != commands.end())
        commands[event.key.keysym.sym]->execute(simulation);
    else
        return;

}
