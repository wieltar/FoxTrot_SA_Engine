#include "Level.h"
#include "Events/EventSingleton.h"
#include "Events/Sound/OnMusicStartEvent.h"


void Level::OnAtach() {}//load all sounds
void Level::Start() {
	auto startEvent = OnMusicStartEvent("FILEPATH");
	EventSingleton::get_instance().dispatchEvent<OnMusicStartEvent>(startEvent);
}//play 1 select sound
void Level::OnDetach() {}//cleaup buffer