#include "glpch.h"
#include "Log.h"
namespace Glitch {

	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("ENGINE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_CoreLogger = spdlog::stdout_color_mt("APP");
		s_CoreLogger->set_level(spdlog::level::trace);
	}
}
