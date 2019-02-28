#pragma once

#include <memory>

#include <spdlog/spdlog.h>

#include "Macros.h"

NS_DD_BEGIN

class DD_API Log
{
	Log() {}
	~Log() {}
public:
	static bool InitLog();

	static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
	static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
private:
	static std::shared_ptr<spdlog::logger> s_CoreLogger;
	static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

#define DD_ERROR(...)         ::DuskDawn::Log::GetClientLogger()->error(__VA_ARGS__)
#define DD_WARN(...)		  ::DuskDawn::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DD_FATAL( ...)	      ::DuskDawn::Log::GetClientLogger()->critical(__VA_ARGS__)
#define DD_INFO(...)		  ::DuskDawn::Log::GetClientLogger()->info(__VA_ARGS__)
#define DD_TRACE( ...)	      ::DuskDawn::Log::GetClientLogger()->trace(__VA_ARGS__)

#define DD_CORE_ERROR(...)    ::DuskDawn::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DD_CORE_WARN(...)     ::DuskDawn::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DD_CORE_FATAL(...)    ::DuskDawn::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define DD_CORE_INFO(...)     ::DuskDawn::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DD_CORE_TRACE(...)    ::DuskDawn::Log::GetCoreLogger()->trace(__VA_ARGS__)

NS_DD_END


