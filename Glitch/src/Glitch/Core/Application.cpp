#include "glpch.h"
#include "Application.h"
namespace Glitch {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		sdlFacade = new SDL2Facade();
		renderer = new Renderer2d(sdlFacade);

		m_window = std::unique_ptr<Window>(Window::Create());

		m_window->SetFacade(sdlFacade);
		m_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		m_window->Init();
		renderer->Init();
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		

		while (isRunning)
		{
			m_window->OnUpdate();
			renderer->OnUpdate();
			// etc. OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		isRunning = false;
		// TODO shutdown all other systems
		return true;
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		GL_INFO(e.ToString());
	}
}