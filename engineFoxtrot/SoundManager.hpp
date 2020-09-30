#pragma once
#include "SDL.h"
#include <map>
#include <string>
#include "Sound.h"
#include "SoundType.h"

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	void init();
	void loadSound();
	void unloadSound();
	void play(string identifier, SoundType* type);

private:
	Sound* ActiveBGM;
	Sound* NewBGM;
	map<string, Sound*> BGMBuffers;
	map<string, Sound*> SFXBuffers;
};