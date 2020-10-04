#pragma once
#include "Glitch/Core/Core.h"
#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Glitch {
	class GLITCH_API Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};
}

#define GL_CORE_FATAL(...)	::Glitch::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define GL_CORE_ERROR(...)	::Glitch::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GL_CORE_WARN(...)	::Glitch::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GL_CORE_INFO(...)	::Glitch::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GL_CORE_TRACE(...)	::Glitch::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define GL_FATAL(...)	::Glitch::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define GL_ERROR(...)	::Glitch::Log::GetClientLogger()->error(__VA_ARGS__)
#define GL_WARN(...)	::Glitch::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GL_INFO(...)	::Glitch::Log::GetClientLogger()->info(__VA_ARGS__)
#define GL_TRACE(...)	::Glitch::Log::GetClientLogger()->trace(__VA_ARGS__)

