#pragma once
#ifdef BUILD_WINDOWS
#ifdef BUILD_DLL
	#define API __declspec(dllexport)
	#define EXPIMP_TEMPLATE
#else
	#define API __declspec(dllimport)
	#define EXPIMP_TEMPLATE extern
#endif // BUILD_DLL

#endif // PLATFORM_WINDOWS