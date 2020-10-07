#include "Glitch.h"

class Game : public Glitch::Application
{
public:
	Game() {};
	~Game() {};
};
Glitch::Application* Glitch::CreateApplication() {
	return new Game();
}
