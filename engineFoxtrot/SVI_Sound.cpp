#include "SVI.h"

// Functions in this cpp file may only call functions in this file. And global SDL2 definitions


void SVI::load(const char* filename) {
	SDL_LoadWAV(filename, &wavSpec, &wavBuffer, &wavLength);
	deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
}

void SVI::play() {
	SDL_QueueAudio(deviceId, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceId, 0);
}