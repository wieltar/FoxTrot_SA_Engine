#pragma once
#ifdef BUILD_WINDOWS
#ifdef BUILD_DLL
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif // BUILD_DLL

#endif // PLATFORM_WINDOWS