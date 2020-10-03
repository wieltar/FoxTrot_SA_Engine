#pragma once
#include "Core.h"
#include "window.h"

namespace Glitch {
	class GLITCH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		std::unique_ptr<Window> m_window;
		bool isRunning = true;
	};
	// to be defined in Game/Client
	Application* CreateApplication(); 
}


