#include "SVIEngine.h"

SVIEngine::SVIEngine()
{
}

SVIEngine::~SVIEngine()
{
}

/// @brief Loads audio files
/// @param filename 
void SVIEngine::load(const char* filename)
{
	sviFacade->load(filename);
}

/// @brief 
/// Plays sounds
void SVIEngine::play()
{
	sviFacade->play();
}

/// @brief TO BE REMOVED
/// @param x 
/// @param y 
void SVIEngine::testLoopVideo(Object& g, Object& b)
{
	sviFacade->testLoopVideo(g,b);
}

/// @brief 
/// Inits SDL2 and creates the window
void SVIEngine::initSDL()
{
	try
	{
		sviFacade->initSDL();
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// Clears the SDL screen
void SVIEngine::clearScreen()
{
	try
	{
	sviFacade->clearScreen();
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// Draws the SDL screen
void SVIEngine::drawScreen()
{
	try
	{
	sviFacade->drawScreen();
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief Loads the PNG files AKA sprites
/// @param spriteID 
/// @param filename
void SVIEngine::loadImage(int spriteID, const char* filename)
{
	try
	{
	sviFacade->loadImage(spriteID, filename);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief Sets the sprite on the screen
/// @param spriteID 
/// @param xPos 
/// @param yPos 
/// @param width 
/// @param height 
/// @param rotation 
void SVIEngine::renderCopy(int spriteID, int xPos, int yPos, int width, int height, int rotation)
{
	try
	{
	sviFacade->renderCopy(spriteID, xPos, yPos, width, height, rotation);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// Update all the sprites on the screen
void SVIEngine::updateScreen()
{
	try
	{
		if (pointerToObjectVector == nullptr) return;
		//if (pointerToObjectVector->capacity() <= 0) return;
		if (pointerToObjectVector->size() <= 0) return;
		for (auto obj : *pointerToObjectVector) {
			if (obj != nullptr) {
				sviFacade->renderCopy(obj->getSpriteID(), obj->getPositionX(), obj->getPositionY(), obj->getWidth(), obj->getHeight(), obj->getRotation());
			}
		}
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// Update function
void SVIEngine::update(Object* object)
{
	
	clearScreen();
	updateScreen();
	drawScreen();
}

void SVIEngine::receiveTick()
{
	clearScreen();
	updateScreen();
	drawScreen();
}

/// @brief 
/// Receives input
void SVIEngine::input()
{
	sviFacade->input();
}

//Sound 
void SVIEngine::SetFiles(map<string, string> files)
{
	sviEngine->SetFiles(files);;
}
void SVIEngine::AddFile(const string& identifier, const string& file)
{
	sviEngine->AddFile(identifier, file);
}
void SVIEngine::PlayEffect(const string& effect, int volume = MAX_VOLUME)
{
	sviEngine->PlayEffect(effect, volume);
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
void SVIEngine::PlayMusic(int volume = MAX_VOLUME)
{
	sviEngine->PlayMusic(volume);
}
void SVIEngine::PlayMusic(const string& identifier, int volume = MAX_VOLUME)
{
	sviEngine->PlayMusic(identifier, volume);
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
void SVIEngine::Flush()
{
	sviEngine->Flush();
}

void SVIEngine::onChangeBackgroundMusic(const string& identifier, int volume = MIX_MAX_VOLUME) {
	if (IdentifierExists(identifier)) {
		if (Mix_PlayingMusic()) {
			ChangeMusic(identifier);
		}
		else {
			LoadMusic(identifier);
			PlayMusic(volume);
		}
	}
}

void SVIEngine::onPlayEffect(const string& identifier, int volume = MIX_MAX_VOLUME) {
	if (IdentifierExists(identifier)) {
		if (IdentifierIsLoaded(identifier)) {
			PlayEffect(identifier, volume);
		}
		else {
			LoadEffect(identifier);
			PlayEffect(identifier, volume);
		}
	}
}

bool SVIEngine::IdentifierExists(const string& identifier)
{
	return sviEngine->IdentifierExists(identifier);
}

bool SVIEngine::IdentifierIsLoaded(const string& identifier)
{
	return sviEngine->IdentifierIsLoaded(identifier);
}
