#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

USING_NS_DD;

std::shared_ptr<spdlog::logger> Log::m_CoreLogger{};
std::shared_ptr<spdlog::logger> Log::m_ClientLogger{};

bool Log::InitLog()
{
	m_CoreLogger = spdlog::stderr_color_mt("CoreLogger");
	m_ClientLogger = spdlog::stderr_color_mt("ClientLogger");

	return (m_CoreLogger != nullptr && m_ClientLogger != nullptr);
}
