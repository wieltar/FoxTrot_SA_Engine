#pragma once
#ifdef GL_PLATFORM_WINDOWS	

extern Glitch::Application* Glitch::CreateApplication();

int main(int argc, char** argv) {
	Glitch::Log::Init();
	GL_CORE_INFO("Initialized logger");

	auto app = Glitch::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif