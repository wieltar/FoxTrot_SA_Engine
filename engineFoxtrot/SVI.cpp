#include "SVI.h"


SVI::SVI() 
{
	initSDL();

	SDL_Init(SDL_INIT_EVERYTHING);
    //Initialize SDL_mixer
    if (Mix_OpenAudio(Audio_Frequency, MIX_DEFAULT_FORMAT, Audio_Channel_Amount, Audio_Chunk_Size) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
}

SVI::~SVI()
{
	/*SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);*/
}