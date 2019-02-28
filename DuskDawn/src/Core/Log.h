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

	static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }
	static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_ClientLogger; }
private:
	static std::shared_ptr<spdlog::logger> m_CoreLogger;
	static std::shared_ptr<spdlog::logger> m_ClientLogger;
};

#define DD_ERROR(x, ...)      ::DuskDawn::Log::GetClientLogger()->error(x, __VA_ARGS__)
#define DD_WARN(x, ...)		  ::DuskDawn::Log::GetClientLogger()->warn(x, __VA_ARGS__)
#define DD_FATAL(x, ...)	  ::DuskDawn::Log::GetClientLogger()->fatal(x, __VA_ARGS__)
#define DD_INFO(x, ...)		  ::DuskDawn::Log::GetClientLogger()->info(x, __VA_ARGS__)
#define DD_TRACE(x, ...)	  ::DuskDawn::Log::GetClientLogger()->trace(x, __VA_ARGS__)

#define DD_CORE_ERROR(x, ...) ::DuskDawn::Log::GetCoreLogger()->error(x, __VA_ARGS__)
#define DD_CORE_WARN(x, ...)  ::DuskDawn::Log::GetCoreLogger()->warn(x, __VA_ARGS__)
#define DD_CORE_FATAL(x, ...) ::DuskDawn::Log::GetCoreLogger()->fatal(x, __VA_ARGS__)
#define DD_CORE_INFO(x, ...)  ::DuskDawn::Log::GetCoreLogger()->info(x, __VA_ARGS__)
#define DD_CORE_TRACE(x, ...) ::DuskDawn::Log::GetCoreLogger()->trace(x, __VA_ARGS__)

NS_DD_END


