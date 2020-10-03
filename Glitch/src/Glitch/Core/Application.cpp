#include "Application.h"

namespace Glitch {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::Create());
		m_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		
		while (isRunning)
		{
			m_window->OnUpdate();
		}
	}
	void Application::OnEvent(Event& e)
	{
		GL_INFO("{0}", e);
	}
}