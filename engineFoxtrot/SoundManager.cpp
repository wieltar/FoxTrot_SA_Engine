#pragma once
#include "SoundManager.h"

SoundManager::SoundManager() {
	Init();
}

SoundManager::~SoundManager() {
	FlushBuffer();
}

void SoundManager::AddFiles(map<string, string> files)
{
	// TODO add validation
	this->musicDictionary = files;
}

void SoundManager::AddFile(string identifier, string file) {
	this->musicDictionary[identifier] = file;
}


void SoundManager::Init()
{
	bool success;
	// Initialize SDL_audio
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
}

void SoundManager::FlushBuffer()
{
	for (auto it = musicDictionary.begin(); it != musicDictionary.end(); /* don't increment here*/) {
		delete &it->second;
		it = musicDictionary.erase(it);  // update here
	}


	for (auto it = sfx.begin(); it != sfx.end(); /* don't increment here*/) {
		delete it->second;
		it = sfx.erase(it);  // update here
	}

	delete music;
}


void SoundManager::PlayEffect(const string& identifier) {
	//Play sound (first parameter is the channel, the last one the amount of loops)
	Mix_PlayChannel(-1, sfx[identifier], 0);
}

void SoundManager::LoadEffect(string identifier, string path) {
	/*
	  Check whether an effect is already loaded, otherwise, load it
		Iterate over all effects that need to be loaded
	*/
	//If the pool doesn't contain the effect, load it
	if (sfx.find(identifier) == sfx.end()) {
		sfx[identifier] = Mix_LoadWAV(path.c_str());
		if (!sfx[identifier]) {
			std::cerr << "Mix_LoadWAV Error: " << Mix_GetError() << std::endl;
		}
	}
}

int SoundManager::StartLoopedEffect(const string& effect) {
	//Play sound forever, and return it's channel
	return Mix_PlayChannel(-1, sfx[effect], -1);
}

void SoundManager::StopLoopedEffect(int channel) {
	//Stop the channel the looped effect is playing on
	Mix_HaltChannel(channel);
}


void SoundManager::LoadMusic(const string identifier) {
	//If old music is loaded (!= NULL), free it
	if (music) {
		Mix_FreeMusic(music);
	}

	// TODO add fade between music
	if (musicDictionary.find(identifier) != musicDictionary.end())
	{
		//Load new music and play it infinitely
		music = Mix_LoadMUS(musicDictionary[identifier].c_str());
		if (!music) {
			std::cerr << "Mix_LoadMUS Error: " << Mix_GetError() << std::endl;
			return;
		}
		Mix_PlayMusic(music, -1);
	}
}