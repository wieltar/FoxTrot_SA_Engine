#include "SVIEngine.h"

SVIEngine::SVIEngine()
{
}

SVIEngine::~SVIEngine()
{
}

void SVIEngine::testLoopVideo(int x, int y)
{
	sviEngine->testLoopVideo(x,y);
}

void SVIEngine::input()
{
	sviEngine->input();
}

//Sound 
//Sound 
void SVIEngine::SetFiles(map<string, string> files)
{
	sviEngine->SetFiles(files);;
}
void SVIEngine::AddFile(const string& identifier, const string& file)
{
	sviEngine->AddFile(identifier, file);
}
void SVIEngine::PlayEffect(const string& effect)
{
	sviEngine->PlayEffect(effect);
}
void SVIEngine::PlayEffect(const string& identifier, int volume)
{
	sviEngine->PlayEffect(identifier, volume);
}
void SVIEngine::LoadEffect(const string& identifier)
{
	sviEngine->LoadEffect(identifier);
}
void SVIEngine::UnloadEffect(const string& identifier)
{
	sviEngine->UnloadEffect(identifier);
}
void SVIEngine::StartLoopedEffect(const string& effect)
{
	sviEngine->StartLoopedEffect(effect);
}
void SVIEngine::StopLoopedEffect(const string& identifier)
{
	sviEngine->StopLoopedEffect(identifier);
}
void SVIEngine::LoadMusic(const string& identifier)
{
	sviEngine->LoadMusic(identifier);
}
void SVIEngine::PlayMusic()
{
	sviEngine->PlayMusic();
}
void SVIEngine::PlayMusic(int volume)
{
	sviEngine->PlayMusic(volume);
}
void SVIEngine::PlayMusic(const string& identifier)
{
	sviEngine->PlayMusic();
}
void SVIEngine::PlayMusic(const string& identifier, int volume)
{
	sviEngine->PlayMusic();
}
void SVIEngine::ChangeMusic(const string& identifier)
{
	sviEngine->ChangeMusic(identifier);
}
void SVIEngine::FadeOutMusic(int fadeTime)
{
	sviEngine->FadeOutMusic(fadeTime);
}
void SVIEngine::FadeInMusic(int fadeTime)
{
	sviEngine->FadeInMusic(fadeTime);
}
void SVIEngine::FadeInMusic(const string& identifier, int fadeTime)
{
	sviEngine->FadeInMusic(identifier, fadeTime);
}
void SVIEngine::RewindMusic()
{
	sviEngine->RewindMusic();
}
void SVIEngine::StopMusic()
{
	sviEngine->StopMusic();
}
void SVIEngine::PauseMusic()
{
	sviEngine->PauseMusic();
}
void SVIEngine::ResumeMusic()
{
	sviEngine->ResumeMusic();
}
void SVIEngine::IsPlayingMusic()
{
	sviEngine->IsPlayingMusic();
}
void SVIEngine::Flush()
{
	sviEngine->Flush();
}