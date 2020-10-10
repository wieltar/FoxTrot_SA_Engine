#include "SVI.h"

/// @brief 
SVI::SVI() 
{
	initSDL();

	SDL_Init(SDL_INIT_EVERYTHING);
    //Initialize SDL_mixer
    if (Mix_OpenAudio(AUDIO_FREQUENCY, MIX_DEFAULT_FORMAT, AUDIO_CHANNEL_AMOUNT, AUDIO_CHUNK_SIZE) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
}

/// @brief 
SVI::~SVI()
{
	/*SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);*/
}