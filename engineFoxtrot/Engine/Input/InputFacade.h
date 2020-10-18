#pragma once
#include "stdafx.h"

#include "Command.h"
#include "SDL.h"
#include "IInputFacade.h"

class InputFacade : public IInputFacade
{

public:
    void setSimulationPointer(Simulation *simulation);

    bool input_mapping();

    InputFacade();
    ~InputFacade();

private:
    Simulation* simulation = nullptr;

    // Pointers to all commands
    Command* startSimulation;
    Command* stopSimulation;
    Command* increaseSimulationSpeed;
    Command* decreaseSimulationSpeed;
    Command* changeCollisionDetection;
    Command* jumpBack;

    map <int, Command*> commands;

    void keydown(SDL_Event& event);

};



