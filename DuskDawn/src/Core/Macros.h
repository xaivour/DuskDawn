#pragma once

#include "DDConfig.h"

#ifdef DD_PLATFORM_WINDOWS
	#ifdef DD_SHARED_BUILD
		#define DD_API __declspec(dllexport)
	#elif DD_SHARED
		#define DD_API __declspec(dllimport)
	#else
		#define DD_API
	#endif
#else
	#define DD_API 
#endif

#define NS_DD_BEGIN namespace DuskDawn {
#define NS_DD_END	}

#define USING_NS_DD using namespace DuskDawn

#ifdef DD_DEBUG
#define DD_ENABLE_ASSERTS
#endif

#ifdef DD_ENABLE_ASSERTS
#define DD_ASSERT(x, ...) { if(!(x)) { DD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define DD_CORE_ASSERT(x, ...) { if(!(x)) { DD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define DD_ASSERT(x, ...)
#define DD_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

