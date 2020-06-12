#pragma once

#ifdef CW_PLATFORM_WINDOWS
	#ifdef CW_BUILD_DLL
		#define CALLOW_API __declspec(dllexport)
	#else
		#define CALLOW_API __declspec(dllimport)
	#endif
#else
	#error Callow engine only supports Windows for now!
#endif