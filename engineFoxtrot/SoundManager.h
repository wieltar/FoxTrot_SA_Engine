#pragma once
#include "SDL.h"
#include "SDL_mixer.h"
#include <map>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	void SetFiles(map<string, string> files);

	void AddFile(const string& identifier, const string& file);

	void PlayEffect(const string& effect);

	void LoadEffect(const string& identifier);

	void UnloadEffect(const string& identifier);

	void StartLoopedEffect(const string& effect);

	void StopLoopedEffect(const string& identifier);

	void LoadMusic(const string& identifier);

	void PlayMusic();

	void StopMusic();

	// TODO create a way to subscribe to events 
	
	void Init();
	void Flush();
private:
	// identifier, path
	map<string, string> soundPaths;
	map<string, int> loopChannels;

private:
	Mix_Music* music;
	std::map<std::string, Mix_Chunk*> sfx;
};