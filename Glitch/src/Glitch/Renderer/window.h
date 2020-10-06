#pragma once
#include "Glitch\Events\ApplicationEvent.h"

namespace Glitch {

	using EventCallbackFn = std::function<void(Event&)>;
	struct WindowProps
	{
		int Id;
		const char* Title;
		unsigned int Width;
		unsigned int Height;
		bool vSync;
		EventCallbackFn EventCallback;

		WindowProps(
			const char* title = "Glitch engine",
			unsigned int width = 1280,
			unsigned int height = 720
		) : Title{ title }, Width{ width }, Height{ height }
		{
			vSync = false;
			Id = 0;
		}
	};

	class GLITCH_API Window
	{
	public:
		

		virtual ~Window() {};

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVsync(bool enabled) = 0;
		virtual bool IsVsync() const = 0;

		virtual WindowProps* GetProperties() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}