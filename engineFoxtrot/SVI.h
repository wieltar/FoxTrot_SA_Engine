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

#define Example_Sound	"../Assets/Sound/b423b42.wav"
#define Example_Sprite  "../Assets/Sprites/simple.png"

#define First_Available_Channel -1
#define Dont_Loop 0
#define Loop_Indefinitely -1

#define Audio_Frequency 44100
#define Audio_Channel_Amount 2
#define Audio_Chunk_Size 2048

#define Window_Width 600
#define Window_Height 400

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
	// Set the files map
	void SetFiles(map<string, string> files);

	// Adds a file to the file dictionary and specify an identifier
	void AddFile(const string& identifier, const string& file);

	// Plays the selected effect (loads it if not yet loaded) at max volume (128)
	void PlayEffect(const string& effect);

	// Plays the selected effect (loads it if not yet loaded). volume ranges from 0 to 128
	void PlayEffect(const string& identifier, int volume);

	// Loads a sound effect into the buffer
	bool LoadEffect(const string& identifier);

	// Unloads a sound effect from the buffer
	void UnloadEffect(const string& identifier);

	// Indefinetely plays an effect
	void StartLoopedEffect(const string& effect);

	// Stops the looping channel identified by the identifier
	void StopLoopedEffect(const string& identifier);

	// Loads a music file into the buffer
	bool LoadMusic(const string& identifier);

	// Plays the currently loaded music at max volume (128)
	void PlayMusic();

	// Plays the currently loaded music. volume ranges from 0 to 128
	void PlayMusic(int volume);

	// Loads and plays music by identifier
	void PlayMusic(const string& identifier);

	// Loads and plays music by identifier. volume ranges from 0 to 128
	void PlayMusic(const string& identifier, int volume);

	// Switches music to audio with identifier
	void ChangeMusic(const string& identifier);

	// Fades out the currently playing music over x milliseconds
	void FadeOutMusic(int fadeTime);

	// Rewinds and fades in the currenlty loaded music
	void FadeInMusic(int fadeTime);

	// Loads the selected music into the buffer and fades it in over x milliseconds
	void FadeInMusic(const string& identifier, int fadeTime);

	// Rewinds the music to the start
	void RewindMusic();

	// Stops the currently playing music
	void StopMusic();

	// Pauses the currenlty playing music
	void PauseMusic();

	// Resumes music if paused
	void ResumeMusic();

	// Return whether music is playing or not
	void IsPlayingMusic();

	// Flushes all buffers and releases memory. This also empties all added files and identifiers
	void Flush();
private:
	// Identifier, path
	map<string, string> soundPaths;

	// Identifier, channelId
	map<string, int> loopChannels;

	// Music buffer
	Mix_Music* music;

	// Identifier, Mix_Chunk*
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



