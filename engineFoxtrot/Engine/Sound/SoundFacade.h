#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#undef main

#include "ISound.h"
#include "../SceneManager/Object.h"

#define EXAMPLE_SOUND	"../Assets/Sound/b423b42.wav"
#define EXAMPLE_SPRITE  "../Assets/Sprites/simple.png"

#define FIRST_AVAILABLE_CHANNEL -1
#define DONT_LOOP 0
#define LOOP_INDEFINITELY -1

#define AUDIO_FREQUENCY 44100
#define AUDIO_CHANNEL_AMOUNT 2
#define AUDIO_CHUNK_SIZE 2048


#if(EXPORT)
class DLLEXPORT SoundFacade : public ISound
#else
/// @brief 
/// SoundFacade is de Sound SDL2 facade
class SoundFacade : public ISound
#endif
{
public:
	SoundFacade();
	~SoundFacade();

	void SetFiles(map<string, string> files);
	void AddFile(const string& identifier, const string& file);
	void PlayEffect(const string& identifier, const int volume);
	void LoadEffect(const string& identifier);
	void UnloadEffect(const string& identifier);
	void StartLoopedEffect(const string& effect);
	void StopLoopedEffect(const string& identifier);
	void LoadMusic(const string& identifier);
	void PlayMusic(const int volume);
	void PlayMusic(const string& identifier, const int volume);
	void ChangeMusic(const string& identifier);
	void FadeOutMusic(const int fadeTime);
	void FadeInMusic(const int fadeTime);
	void FadeInMusic(const string& identifier, const int fadeTime);
	void RewindMusic();
	void StopMusic();
	void PauseMusic();
	void ResumeMusic();
	void Flush();
	bool IdentifierExists(const string& identifier);
	bool IdentifierIsLoaded(const string& identifier);
private:
	map<string, string> soundPaths;
	map<string, int> loopChannels;
	Mix_Music* music;
	std::map<std::string, Mix_Chunk*> loadedSoundEffects;

};