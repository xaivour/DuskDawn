#pragma once

#include <iostream>

#include "Log.h"
#include "Macros.h"

#if defined(DD_PLATFORM_WINDOWS) || defined(DD_PLATFORM_LINUX) || defined(DD_PLATFORM_MAC)

USING_NS_DD;

int main()
{
	Log::InitLog();
	DD_CORE_WARN("Log initialized");
	DD_CORE_INFO("Dusk Dawn version 0x{:x}", DD_VERSION_HEX);

	std::cin.get();
	return 0;
}

#endif
