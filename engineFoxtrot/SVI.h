#pragma once

#include "ISVI.h"
#include "Debug.h"
#include "ErrorCodes.h"
#include "GeneralHelperFunctions.cpp"
#include "SDL.h"
#include "Sound.h"
#include <string>
#include <map>
#include <memory>
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <unordered_map>
#undef main

using namespace std;

#define EXAMPLE_SOUND	"../Assets/Sound/b423b42.wav"
#define EXAMPLE_SPRITE  "../Assets/Sprites/simple.png"

#define FIRST_AVAILABLE_CHANNEL -1
#define DONT_LOOP 0
#define LOOP_INDEFINITELY -1

#define AUDIO_FREQUENCY 44100
#define AUDIO_CHANNEL_AMOUNT 2
#define AUDIO_CHUNK_SIZE 2048

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

#if(EXPORT)
class DLLEXPORT SVI : public ISVI
#else
/// @brief 
/// SVI is de SDL2 facade
class SVI : public ISVI
#endif
{
// General stuff
public:
	SVI();
	~SVI();


private:
	SDL_Renderer* renderer;
	SDL_Window* window;



// Sound functions
public:
	void SetFiles(map<string, string> files);
	void AddFile(const string& identifier, const string& file);
	void PlayEffect(const string& identifier, int volume);
	void LoadEffect(const string& identifier);
	void UnloadEffect(const string& identifier);
	void StartLoopedEffect(const string& effect);
	void StopLoopedEffect(const string& identifier);
	void LoadMusic(const string& identifier);
	void PlayMusic(int volume);
	void PlayMusic(const string& identifier, int volume);
	void ChangeMusic(const string& identifier);
	void FadeOutMusic(int fadeTime);
	void FadeInMusic(int fadeTime);
	void FadeInMusic(const string& identifier, int fadeTime);
	void RewindMusic();
	void StopMusic();
	void PauseMusic();
	void ResumeMusic();
	void Flush();
	bool IdentifierExists(const string& identifier);
	bool IdentifierIsLoaded(const string& identifier);

	void onChangeBackgroundMusic(const string& identifier, int volume);
	void onPlayEffect(const string& identifier, int volume);
private:
	map<string, string> soundPaths;
	map<string, int> loopChannels;
	Mix_Music* music;
	std::map<std::string, Mix_Chunk*> loadedSoundEffects;

// Video functions
public:
	void testLoopVideo(int x, int y);

	void initSDL();

	void clearScreen();
	void drawScreen();
	void loadImage(int spriteID, const char* filename);

	void renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation);


	unordered_map<int, SDL_Texture*> textureMap;

private:


// Input functions
public:
	void input();

private:
	int mousex = 0;
	int mousey = 0;
};