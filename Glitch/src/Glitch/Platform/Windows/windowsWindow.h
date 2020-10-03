#pragma once
#include "Glitch\window.h"
#include "SDL.h"
namespace Glitch {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		~WindowsWindow() override;

		// Inherited via Window
		virtual void OnUpdate() override;
		virtual unsigned int GetWidth() const override { return m_data.Width; }
		virtual unsigned int GetHeight() const override { return m_data.Height; }
		virtual void SetEventCallback(const EventCallbackFn& callback) override { m_data.EventCallback = callback; }
		virtual void SetVsync(bool enabled) override;
		virtual bool IsVsync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		void PollEvents();

		struct WindowData {
			const char* Title;
			int Width;
			int Height;
			bool vSync;

			EventCallbackFn EventCallback;
		};

		SDL_Window* window = nullptr;
		SDL_Surface* screenSurface;
		SDL_Renderer* renderer;
		
		static WindowData m_data;

	};
}

