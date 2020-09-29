#pragma once
#include "SVI.h"
class Sound {
	public:
		SDL_AudioSpec wavSpec;
		Uint32 wavLength;
		Uint8* wavBuffer;
		SDL_AudioDeviceID deviceId;
};