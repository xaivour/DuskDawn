#pragma once

#include <iostream>

#include "Log.h"
#include "Macros.h"

#if defined(DD_PLATFORM_WINDOWS) || defined(DD_PLATFORM_LINUX) || defined(DD_PLATFORM_MAC)

extern DuskDawn::Application* DuskDawn::CreateApplication();

int main(int argc, char* argv[])
{
	DuskDawn::Log::InitLog();
	DD_CORE_WARN("Log initialized");
	DD_CORE_INFO("Starting DuskDawn Version {}", DD_VERSION);

	auto app = DuskDawn::CreateApplication();

	DD_CORE_ASSERT(app != nullptr, "app == nullptr : App creation failed");

	app->Run();
	delete app;

	return 0;
}

#endif
