#include "SVI.h"


SVI::SVI() 
{
	initSDL();
    int audioFrequency = 44100;
    int audioChannelAmount = 2;
    int audioChunkSize = 2048;

	SDL_Init(SDL_INIT_EVERYTHING);
    //Initialize SDL_mixer
    if (Mix_OpenAudio(audioFrequency, MIX_DEFAULT_FORMAT, audioChannelAmount, audioChunkSize) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
}

SVI::~SVI()
{
	/*SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);*/
}