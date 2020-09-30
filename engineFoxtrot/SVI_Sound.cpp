#include "SVI.h"

// Functions in this cpp file may only call functions in this file. And global SDL2 definitions

// Loads the sound file into memory and sets identifier for easy access
void SVI::load(string filename, string identifier) {
	Sound* sound = new Sound();
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;
	SDL_LoadWAV(filename.c_str(), &wavSpec, &wavBuffer, &wavLength);
	sound->wavBuffer = wavBuffer;
	sound->wavLength = wavLength;
	sound->wavSpec = wavSpec;
	sound->deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
	devices.insert(pair<string, Sound*>(identifier, sound));
}

void SVI::play(string identifier) {
	if (devices.find(identifier) == devices.end()) {
		std::cout << "Sound with identifier \"" << identifier << "\" not found" << std::endl;
		return;
	}
	Sound* sound = devices.at(identifier);
	SDL_QueueAudio(sound->deviceId, sound->wavBuffer, sound->wavLength);
	SDL_PauseAudioDevice(sound->deviceId, 0);
}

void SVI::stop(string identifier) {
	if (devices.find(identifier) == devices.end()) {
		std::cout << "Sound with identifier \"" << identifier << "\" not found" << std::endl;
		return;
	}
	Sound* sound = devices.at(identifier);
	SDL_PauseAudioDevice(sound->deviceId, 1);
}

void SVI::unload(string identifier) {
	std::map<std::string, Sound*>::iterator itr = devices.find(identifier);
	if (itr != devices.end())
	{
		delete itr->second;
		devices.erase(itr);
		return;
	}
	std::cout << "Sound with identifier \"" << identifier << "\" not found" << std::endl;
}

void SVI::flush() {
	for (auto it = devices.begin(); it != devices.end(); /* don't increment here*/) {
		delete it->second;
		it = devices.erase(it);  // update here
	}
}