#include "InputFacade.h"


InputFacade::InputFacade()
{
    // Create pointers to all commands (to apply the flyweight pattern)
    startSimulation = new StartSimulation();
    stopSimulation = new StopSimulation();
    increaseSimulationSpeed = new IncreaseSimulationSpeed();
    decreaseSimulationSpeed = new DecreaseSimulationSpeed();
    changeCollisionDetection = new ChangeCollisionDetection();
    jumpBack = new JumpBack();

    commands[SDLK_q] = startSimulation;
    commands[SDLK_w] = stopSimulation;
    commands[SDLK_e] = increaseSimulationSpeed;
    commands[SDLK_r] = decreaseSimulationSpeed;
    commands[SDLK_t] = changeCollisionDetection;
    commands[SDLK_y] = jumpBack;
}

InputFacade::~InputFacade()
{

}

void InputFacade::setSimulationPointer(Simulation* _simulation)
{
    simulation = _simulation;
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
            //TODO een stop simulation en close screen bouwen
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


