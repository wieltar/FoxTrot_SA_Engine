#pragma once
#include "SVI.h"

class SVIEngine
{
public:
	SVIEngine();
	~SVIEngine();
	
	// Video Functions
	void testLoopVideo(int x, int y);

	// Input Functions
	void input();

	// Sound functions
	void SetFiles(map<string, string> files);
	void AddFile(const string& identifier, const string& file);
	void PlayEffect(const string& effect);
	void PlayEffect(const string& identifier, int volume);
	void LoadEffect(const string& identifier);
	void UnloadEffect(const string& identifier);
	void StartLoopedEffect(const string& effect);
	void StopLoopedEffect(const string& identifier);
	void LoadMusic(const string& identifier);
	void PlayMusic();
	void PlayMusic(int volume);
	void PlayMusic(const string& identifier);
	void PlayMusic(const string& identifier, int volume);
	void ChangeMusic(const string& identifier);
	void FadeOutMusic(int fadeTime);
	void FadeInMusic(int fadeTime);
	void FadeInMusic(const string& identifier, int fadeTime);
	void RewindMusic();
	void StopMusic();
	void PauseMusic();
	void ResumeMusic();
	void IsPlayingMusic();
	void Flush();

	//Set to private after testing!!!
	ISVI * sviEngine = new SVI;
private:
};
