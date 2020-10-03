#pragma once
#include "ErrorCodes.h"

#ifdef GL_PLATFORM_WINDOWS
	#ifdef GL_BUILD_DLL
		#define GLITCH_API __declspec(dllexport)
	#else
		#define GLITCH_API __declspec(dllimport)
	#endif // GL_BUILD_DLL

#endif // GL_PLATFORM_WINDOWS

#ifdef GL_ENABLE_ASSERT
	#define GL_ASSERT(x, ...) { if(!x) {GL_ERROR("Assertion failed {0}", __VA_ARGS__); __debugbreak(); } }
	#define GL_CORE_ASSERT(x, ...) { if(!x) {GL_CORE_ERROR("Assertion failed {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GL_ASSERT(x, ...)
	#define GL_CORE_ASSERT(x, ...) 
#endif // GL_ENABLE_ASSERT

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
