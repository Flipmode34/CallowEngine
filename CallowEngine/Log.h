#pragma once

#include "Core.h"
#include "vendor/spdlog/include/spdlog/spdlog.h"
#include <memory>

namespace Callow
{
	class CALLOW_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define CW_CORE_TRACE(...)	::Callow::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CW_CORE_INFO(...)	::Callow::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CW_CORE_WARN(...)	::Callow::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CW_CORE_ERROR(...)	::Callow::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CW_CORE_FATAL(...)	::Callow::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CW_TRACE(...)		::Callow::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CW_INFO(...)		::Callow::Log::GetClientLogger()->info(__VA_ARGS__)
#define CW_WARN(...)		::Callow::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CW_ERROR(...)		::Callow::Log::GetClientLogger()->error(__VA_ARGS__)
#define CW_FATAL(...)		::Callow::Log::GetClientLogger()->fatal(__VA_ARGS__)