#include "SVI.h"

// Functions in this cpp file may only call functions in this file. And global SDL2 definitions
void SVI::SetFiles(map<string, string> files)
{
	this->soundPaths = files;
}

void SVI::AddFile(const string& identifier, const string& file) {
	this->soundPaths[identifier] = file;
}

void SVI::Flush()
{
	for (auto it = sfx.begin(); it != sfx.end(); /* don't increment here*/) {
		it = sfx.erase(it);  // update here
	}
	for (auto it = loopChannels.begin(); it != loopChannels.end(); /* don't increment here*/) {
		it = loopChannels.erase(it);  // update here
	}
}

void SVI::PlayEffect(const string& identifier) {
	//Play sound (first parameter is the channel, the last one the amount of loops)
	if (soundPaths.find(identifier) != soundPaths.end() && sfx.find(identifier) == sfx.end()) {
		LoadEffect(identifier);
	}
	if (sfx.find(identifier) != sfx.end()) {
		int channel = Mix_PlayChannel(-1, sfx[identifier], 0);
		Mix_Volume(channel, MIX_MAX_VOLUME);
	}
}

void SVI::PlayEffect(const string& identifier, int volume) {
	//Play sound (first parameter is the channel, the last one the amount of loops)
	if (soundPaths.find(identifier) != soundPaths.end() && sfx.find(identifier) == sfx.end()) {
		LoadEffect(identifier);
	}
	if (sfx.find(identifier) != sfx.end()) {
		int channel = Mix_PlayChannel(-1, sfx[identifier], 0);
		Mix_Volume(channel, volume);
	}
}

//Check whether an effect is already loaded, otherwise, load it.
void SVI::LoadEffect(const string& identifier) {
	if (sfx.find(identifier) == sfx.end()) {
		sfx[identifier] = Mix_LoadWAV(soundPaths.at(identifier).c_str());
		if (!sfx[identifier]) {
			std::cerr << "Mix_LoadWAV Error: " << Mix_GetError() << std::endl;
		}
	}
}

void SVI::UnloadEffect(const string& identifier) {
	if (sfx.find(identifier) == sfx.end()) {
		return;
	}
	StopLoopedEffect(identifier);
	sfx.erase(identifier);
	loopChannels.erase(identifier);
}

void SVI::StartLoopedEffect(const string& identifier) {
	//Play sound forever and save it in the loopChannels map
	if (sfx.find(identifier) != sfx.end()) {
		int channel = Mix_PlayChannel(-1, sfx[identifier], -1);
		loopChannels.insert(pair<string, int>(identifier, channel));
	}
}

void SVI::StopLoopedEffect(const string& identifier) {
	//Stop the channel the looped effect is playing on
	if (loopChannels.find(identifier) != loopChannels.end()) {
		Mix_HaltChannel(loopChannels[identifier]);
		loopChannels.erase(identifier);
	}
}

void SVI::LoadMusic(const string& identifier) {
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

void SVI::PlayMusic() {
	Mix_VolumeMusic(MIX_MAX_VOLUME);
	Mix_PlayMusic(music, -1);
}

void SVI::PlayMusic(int volume) {
	Mix_VolumeMusic(volume);
	Mix_PlayMusic(music, -1);
}

void SVI::PlayMusic(const string& identifier) {
	if (soundPaths.find(identifier) != soundPaths.end()) {
		LoadMusic(identifier);
		Mix_VolumeMusic(MIX_MAX_VOLUME);
		Mix_PlayMusic(music, -1);
	}
}

void SVI::PlayMusic(const string& identifier, int volume) {
	if (soundPaths.find(identifier) != soundPaths.end()) {
		LoadMusic(identifier);
		Mix_VolumeMusic(volume);
		Mix_PlayMusic(music, -1);
	}
}

void SVI::ChangeMusic(const string& identifier) {
	StopMusic();
	LoadMusic(identifier);
	PlayMusic();
}

void SVI::FadeOutMusic(int fadeTime) {
	Mix_FadeOutMusic(fadeTime);
}

void SVI::FadeInMusic(int fadeTime) {
	RewindMusic();
	Mix_FadeInMusic(music, -1, fadeTime);
}

void SVI::FadeInMusic(const string& identifier, int fadeTime) {
	StopMusic();
	LoadMusic(identifier);
	Mix_FadeInMusic(music, -1, fadeTime);
}

void SVI::RewindMusic() {
	Mix_RewindMusic();
}

void SVI::StopMusic() {
	Mix_PauseMusic();
}

void SVI::PauseMusic() {
	Mix_PauseMusic();
}

void SVI::ResumeMusic() {
	Mix_ResumeMusic();
}

void SVI::IsPlayingMusic() {
	Mix_PlayingMusic();
}