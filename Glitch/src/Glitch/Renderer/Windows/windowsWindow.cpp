#include "glpch.h"
#include "windowsWindow.h"

template <typename E>
constexpr auto to_underlying(E e) noexcept
{
	return static_cast<std::underlying_type_t<E>>(e);
}

namespace Glitch {
	
	static bool p_isSDLInitialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	void Window::Init()
	{
	}

	void Window::Shutdown()
	{
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		m_data = new WindowProps();
		m_data->Title = props.Title;
		m_data->Width = props.Width;
		m_data->Height = props.Height;
		//Init(props);
	}

	void WindowsWindow::OnUpdate()
	{
		PollEvents();
		// render update stuff

	}

	void WindowsWindow::PollEvents()
	{
		SDL_Event sdl_event;
		if (&sdl_event)
		{
			while (SDL_PollEvent(&sdl_event))
			{
				WindowProps& winData = *(WindowProps*)SDL_GetWindowData(facade->getWindow(), m_data->Title);

				switch (sdl_event.type)
				{
					// ------ KEYBOARD COMMANDS --------------------------------
					case SDL_KEYDOWN: {
						int sdl_int = (int) to_underlying(sdl_event.key.keysym.scancode);
						KeyPressedEvent event(static_cast<KeyCode>(sdl_int), sdl_event.key.repeat);
						winData.EventCallback(event);
						break;
					}
					case SDL_KEYUP: {
						int sdl_int = (int)to_underlying(sdl_event.key.keysym.scancode);
						KeyReleasedEvent event(static_cast<KeyCode>(sdl_int));
						winData.EventCallback(event);
						break;
					}
					// ------ MOUSE COMMANDS ------------------------------------
					case SDL_MOUSEBUTTONDOWN: {
						MouseButtonPressedEvent event(sdl_event.button.button);
						winData.EventCallback(event);
						break;
					}
					case SDL_MOUSEBUTTONUP: {
						MouseButtonReleasedEvent event(sdl_event.button.button);
						winData.EventCallback(event);
						break;
					}
					case SDL_MOUSEWHEEL: {
						MouseScrolledEvent event(sdl_event.wheel.x, sdl_event.wheel.y);
						winData.EventCallback(event);
						break;
					}
					case SDL_MOUSEMOTION: {
						int mouseX, mouseY;
						SDL_GetGlobalMouseState(&mouseX, &mouseY);

						MouseMovedEvent event(mouseX, mouseY);
						winData.EventCallback(event);
						break;
					}
					// ------ WINDOW COMMANDS --------------------------------
					case SDL_QUIT:
						Shutdown();
						break;
					case SDL_WINDOWEVENT: {
						if (sdl_event.window.event == SDL_WINDOWEVENT_CLOSE)
						{
							WindowCloseEvent event;
							winData.EventCallback(event);
						}
						else if (sdl_event.window.event == SDL_WINDOWEVENT_RESIZED) {
							WindowResizeEvent event(winData.Width, winData.Height);
							SDL_SetWindowSize(facade->getWindow(), winData.Width, winData.Height);
							winData.EventCallback(event);
						}
						break;
					}
				}

			}
		}
	}

	void WindowsWindow::SetVsync(bool enabled)
	{
		// TODO Implement vsync enabeling
		m_data->vSync = enabled;
	}

	void WindowsWindow::Init()
	{
		
		GL_CORE_INFO("Intialized window {0}, ({1}, {2})", m_data->Title, m_data->Width, m_data->Height);
		facade->createWindow(m_data);
	}

	void WindowsWindow::Shutdown()
	{
		facade->destroyScreen();
	}

	bool WindowsWindow::IsVsync() const {
		return m_data->vSync;
	}
}
