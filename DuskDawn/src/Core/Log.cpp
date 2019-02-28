#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

USING_NS_DD;

std::shared_ptr<spdlog::logger> Log::s_CoreLogger{};
std::shared_ptr<spdlog::logger> Log::s_ClientLogger{};

bool Log::InitLog()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");
	s_CoreLogger = spdlog::stderr_color_mt("DuskDawn");
	s_ClientLogger = spdlog::stderr_color_mt("APP");

	return (s_CoreLogger != nullptr && s_ClientLogger != nullptr);
}
