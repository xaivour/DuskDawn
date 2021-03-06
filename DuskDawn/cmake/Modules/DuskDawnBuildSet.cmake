set(DD_VERSION ${PROJECT_VERSION})
set(DD_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(DD_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(DD_VERSION_PATCH ${PROJECT_VERSION_PATCH})

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
set(LINUX 1)
set(DD_PLATFORM_LINUX 1)
add_definitions(-DDD_PLATFORM_LINUX)
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
set(WINDOWS 1)
set(DD_PLATFORM_WINDOWS 1)
add_definitions(-DDD_PLATFORM_WINDOWS)
elseif(ANDROID)
set(DD_PLATFORM_ANDROID 1)
add_definitions(-DDD_PLATFORM_ANDROID)
elseif(APPLE)
if(CMAKE_SYSTEM_NAME MATCHES "iOS")
add_definitions(-DDD_PLATFORM_IOS)
set(IOS 1)
set(DD_PLATFORM_IOS 1)
elseif(CMAKE_SYSTEM_NAME MATCHES "MacOSX")
add_definitions(-DDD_PATFORM_MACOSX)
set(MACOSX 1)
set(DD_PLATFORM_MACOSX 1)
endif()
else()
message(FATAL_ERROR "Current Platform not supported")
endif()

if(${DEBUG_MODE} MATCHES ON)
set(DD_DEBUG 1)
else()
set(DD_RELEASE 1)
endif()
