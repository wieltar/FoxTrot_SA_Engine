#pragma once
#include "../Events/EventManager.h"
#include "SVI.h"


#define MAX_VOLUME 128

/// @brief 
/// SVIEngine is the SDL2 wrapper

#if(EXPORT)
class DLLEXPORT SVIEngine
#else
class SVIEngine : public EventListener
#endif
{
public:
	SVIEngine();
	~SVIEngine();
	
	void update(Object* object) override;

	// Input Functions
	void input();

	// Sound functions
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

	vector <Object*>*pointerToObjectVector = nullptr;

	//Set to private after testing!!!
	EventManager* eventManager = nullptr;
	ISVI * sviFacade = new SVI;
private:
};
