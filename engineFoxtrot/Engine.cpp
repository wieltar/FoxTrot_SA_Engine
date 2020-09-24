#include "Engine.h"
#include <functional>

SVI svi;

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::RegsiterCommand(std::function<void> *callback, int inputType, int key, int mouseBtn) {
	svi.sviEngine->RegisterCommand(*callback, inputType, key, mouseBtn);
}
void Engine::InputHandle() {
	svi.sviEngine->InputHandle();
}