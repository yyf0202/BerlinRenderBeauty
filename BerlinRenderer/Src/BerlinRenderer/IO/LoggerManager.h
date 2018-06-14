#pragma once

#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/Utils/StringUtil.h>
#include <BerlinRenderer/Base/Context.h>

#define LOG_INFO(fmt, ...) RENDER Context::GetInstance().LoggerManagerInstance().LogInfo(fmt, __VA_ARGS__)
#define LOG_WARNING(fmt, ...) RENDER Context::GetInstance().LoggerManagerInstance().LogWarning(fmt, __VA_ARGS__)
#define LOG_ERROR(fmt, ...) RENDER Context::GetInstance().LoggerManagerInstance().LogError(fmt, __VA_ARGS__)
#define GL_LOG(fmt, ...) RENDER Context::GetInstance().LoggerManagerInstance().LogInfo(fmt, __VA_ARGS__)

#define CHECK_OPENGL() \
	do \
	{ \
		auto error = glGetError(); \
		if (error != 0) \
		{ \
			GL_LOG("OpenGL error 0x%04X in %s %s %d\n", error, __FILE__, __FUNCTION__, __LINE__); \
		} \
	} \
	while (0)

NS_RENDER_BEGIN

enum LogLevel
{
	Info = 0,
	Warning,
	Error,
	LogLevelMax,
};


class LoggerManager
{
public:
	~LoggerManager();

	template<typename... Args>
	void LogInfo(const char* msg, Args... args)
	{
		DoLog(s_LevelInfo[LogLevel::Info] + StringUtil::Format(msg, args...) + "\n");
	}

	template<typename... Args>
	void LogInfo(string_t msg, Args... args)
	{
		DoLog(s_LevelInfo[LogLevel::Info] + StringUtil::Format(msg.c_str(), args...) + "\n");
	}

	template<typename... Args>
	void LogWarning(const char* msg, Args... args)
	{
		DoLog(s_LevelInfo[LogLevel::Warning] + StringUtil::Format(msg, args...) + "\n");
	}

	template<typename... Args>
	void LogWarning(string_t msg, Args... args)
	{
		DoLog(s_LevelInfo[LogLevel::Warning] + StringUtil::Format(msg.c_str(), args...) + "\n");
	}

	template<typename... Args>
	void LogError(const char* msg, Args... args)
	{
		DoLog(s_LevelInfo[LogLevel::Error] + StringUtil::Format(msg, args...) + "\n");
	}

	template<typename... Args>
	void LogError(string_t msg, Args... args)
	{
		DoLog(s_LevelInfo[LogLevel::Error] + StringUtil::Format(msg.c_str(), args...) + "\n");
	}

	void Init(string_t cfg_path);
	void Update();

	void SetLogCallback(function_t<void(string_t&)> callback) { callback_ = callback; }

private:
	void DoLog(string_t msg);

private:
	static string_t s_LevelInfo[];
	vector_t<string_t> delayMsg_;
	mutex_t locker;
	FILE* file_ = nullptr;
	function_t<void(string_t&)> callback_ = nullptr;
};


NS_RENDER_END