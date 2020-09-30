#pragma once
#include "SVI.h"

#include "SDL.h"
#include "SDL_mixer.h"

class Sound {
public:

	virtual void Play() = 0;
	virtual void Pause() = 0;
	virtual void Stop() = 0;

	int GetDeviceID() { return deviceId; }

	void ClearBuffer() {
		// TODO clear sound buffer
	}

		SDL_AudioSpec wavSpec;
		 Uint32 wavLength;
		 Uint8* wavBuffer;
		 SDL_AudioDeviceID deviceId;
};