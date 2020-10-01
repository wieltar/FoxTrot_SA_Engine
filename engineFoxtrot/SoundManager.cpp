#pragma once
#include "SoundManager.h"

SoundManager::SoundManager() {
	Init();
}

SoundManager::~SoundManager() {
	Flush();
}

void SoundManager::SetFiles(map<string, string> files)
{
	this->soundPaths = files;
}

void SoundManager::AddFile(const string& identifier, const string& file) {
	this->soundPaths[identifier] = file;
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

void SoundManager::Flush()
{
	for (auto it = sfx.begin(); it != sfx.end(); /* don't increment here*/) {
		it = sfx.erase(it);  // update here
	}
	for (auto it = loopChannels.begin(); it != loopChannels.end(); /* don't increment here*/) {
		it = loopChannels.erase(it);  // update here
	}
}

void SoundManager::PlayEffect(const string& identifier) {
	//Play sound (first parameter is the channel, the last one the amount of loops)
	Mix_PlayChannel(-1, sfx[identifier], 0);
}

//Check whether an effect is already loaded, otherwise, load it.
void SoundManager::LoadEffect(const string& identifier) {
	if (sfx.find(identifier) == sfx.end()) {
		sfx[identifier] = Mix_LoadWAV(soundPaths.at(identifier).c_str());
		if (!sfx[identifier]) {
			std::cerr << "Mix_LoadWAV Error: " << Mix_GetError() << std::endl;
		}
	}
}

void SoundManager::UnloadEffect(const string& identifier) {
	if (sfx.find(identifier) == sfx.end()) {
		return;
	}
	StopLoopedEffect(identifier);
	sfx.erase(identifier);
}

void SoundManager::StartLoopedEffect(const string& identifier) {
	//Play sound forever and save it in the loopChannels map
	if (sfx.find(identifier) != sfx.end()) {
		int channel = Mix_PlayChannel(-1, sfx[identifier], -1);
		loopChannels.insert(pair<string, int>(identifier, channel));
	}
}

void SoundManager::StopLoopedEffect(const string& identifier) {
	//Stop the channel the looped effect is playing on
	if (loopChannels.find(identifier) != loopChannels.end()) {
		Mix_HaltChannel(loopChannels[identifier]);
		loopChannels.erase(identifier);
	}
}

void SoundManager::LoadMusic(const string& identifier) {
	//If old music is loaded (!= NULL), free it
	if (music) {
		Mix_FreeMusic(music);
	}

	// TODO add fade between music
	if (soundPaths.find(identifier) != soundPaths.end())
	{
		//Load new music and play it infinitely
		music = Mix_LoadMUS(soundPaths[identifier].c_str());
		if (!music) {
			std::cerr << "Mix_LoadMUS Error: " << Mix_GetError() << std::endl;
			return;
		}
	}
}

void SoundManager::PlayMusic() {
	Mix_PlayMusic(music, -1);
}

void SoundManager::StopMusic() {
	Mix_PauseMusic();
}