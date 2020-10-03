#pragma once
#include "glpch.h"
#include <Glitch\Events\ApplicationEvent.h>

namespace Glitch {
	struct WindowProps
	{
		const char* Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(
			const char* title = "Glitch engine",
			unsigned int width = 1280,
			unsigned int height = 720
		) : Title{ title }, Width{ width }, Height{ height }
		{
		}
	};

	class GLITCH_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {};

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVsync(bool enabled) = 0;
		virtual bool IsVsync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}