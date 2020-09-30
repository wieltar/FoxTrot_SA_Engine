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

	void AddFiles(map<string, string> files);

	void AddFile(string identifier, string file);

	void PlayEffect(const string& effect);

	void LoadEffect(string identifier, string path);

	int StartLoopedEffect(const string& effect);

	void StopLoopedEffect(int channel);

	void LoadMusic(const string file);

	// TODO create a way to subscribe to events 
	
	void Init();
	void FlushBuffer();
private:
	// identifier, path
	map<string, string> musicDictionary;

private:
	Mix_Music* music;
	std::map<std::string, Mix_Chunk*> sfx;
};