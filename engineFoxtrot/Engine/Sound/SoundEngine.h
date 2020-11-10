#pragma once
#include "SceneManager/SceneManager.h" //TODO check this
#include "SceneManager/Scene.h"
#include "SoundFacade.h"
#include "Events/Event.h"

#define MAX_VOLUME 128

/// @brief 
/// SoundEngine is the Sound SDL2 wrapper
class API SoundEngine
{
public:
	SoundEngine();
	~SoundEngine();

	void SetFiles(map<string, string> files);
	void AddFile(const string& identifier, const string& file);
	void PlayEffect(const string& identifier, const int volume);
	void LoadEffect(const string& identifier);
	void UnloadEffect(const string& identifier);
	void StartLoopedEffect(const string& effect);
	void StopLoopedEffect(const string& identifier);
	void LoadMusic(const string& identifier);
	void PlayMusic(const int volume);
	void PlayMusic(const string& identifier, const int volume);
	void ChangeMusic(const string& identifier);
	void FadeOutMusic(const int fadeTime);
	void FadeInMusic(const int fadeTime);
	void FadeInMusic(const string& identifier, const int fadeTime);
	void RewindMusic();
	void StopMusic();
	void PauseMusic();
	void ResumeMusic();
	void Flush();
	void onPlayEffect(const string& identifier, const int volume);
	void onChangeBackgroundMusic(const string& identifier, const int volume);

	bool IdentifierExists(const string& identifier);
	bool IdentifierIsLoaded(const string& identifier);

	void EventListners(); 
	void Event_StartEvent(Event& event);
	void Event_AttachEvent(Event& event);

private:
	ISoundFacade* soundFacade = new SoundFacade;

};
