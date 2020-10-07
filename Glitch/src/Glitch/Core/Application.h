#pragma once
#include "Core.h"
#include "Glitch/Renderer/window.h"
#include <Glitch\Renderer\SceneManager\SceneManager.h>
#include <Glitch\Renderer\Renderer2d.h>

namespace Glitch {
	class GLITCH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		SDL2Facade* sdlFacade;
		
		SceneManager* sceneManager;
		Renderer2d* renderer;


		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_window;
		bool isRunning = true;
	};
	// to be defined in Game/Client
	Application* CreateApplication(); 
}


