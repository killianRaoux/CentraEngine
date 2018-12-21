#pragma once
#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>
namespace GameEngine
{
	class CT_API Log
	{
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;}
	};
}

#define CT_CORE_ERROR(...)    ::GameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CT_CORE_WARN(...)     ::GameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CT_CORE_INFO(...)     ::GameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CT_CORE_TRACE(...)    ::GameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CT_CORE_CRITICAL(...) ::GameEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define CT_ERROR(...)    ::GameEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CT_WARM(...)     ::GameEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CT_INFO(...)     ::GameEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CT_TRACE(...)    ::GameEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CT_CRITICAL(...) ::GameEngine::Log::GetClientLogger()->critical(__VA_ARGS__)