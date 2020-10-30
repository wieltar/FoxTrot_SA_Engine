#include "stdafx.h"
#include "Level.h"
#include "Events/EventSingleton.h"
#include "Events/Sound/OnMusicStartEvent.h"
#include "Events\Sound\SoundAttachEvent.h"
#include "Events\Sound\OnMusicStopEvent.h"


/// @brief 
/// @param sceneID 
Level::Level(const int id, map<string, string> _sounds = map<string, string>()) : Scene::Scene(id), sounds(_sounds)
{
	OnAtach();
}
void Level::OnAtach() {
	for (const auto& s : sounds) {
		std::cout << s.first << " has value " << s.second << std::endl;
		EventSingleton::get_instance().dispatchEvent<SoundAttachEvent>((Event&)SoundAttachEvent(s.first, s.second));
	}
}
void Level::Start() {
	EventSingleton::get_instance().dispatchEvent<OnMusicStartEvent>((Event&)OnMusicStartEvent("Level_1_Sound"));
}
void Level::Pause() {
	EventSingleton::get_instance().dispatchEvent<OnMusicStopEvent>((Event&)OnMusicStopEvent("Level_1_Sound"));
}

void Level::OnDetach() {}//cleaup buffer