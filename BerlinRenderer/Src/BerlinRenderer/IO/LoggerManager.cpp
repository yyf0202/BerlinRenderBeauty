
#include "LoggerManager.h"

#include <BerlinRenderer/Base/Context.h>

NS_RENDER_BEGIN

string_t LoggerManager::s_LevelInfo[LogLevel::LogLevelMax] =
{
	string_t("[Info]: "),
	string_t("[Warning]: "),
	string_t("[Error]: ")
};

LoggerManager::~LoggerManager()
{
	if (file_ != nullptr)
	{
		fclose(file_);
		file_ = nullptr;
	}
}

void LoggerManager::DoLog(string_t msg)
{
	if (Context::GetInstance().IsMainThread())
	{
		fwrite(msg.c_str(), 1, msg.size(), file_);
		fflush(file_);

		if (callback_ != nullptr) callback_(msg);
	}
	else
	{
		locker.lock();
		{
			delayMsg_.push_back(msg);
		}
		locker.unlock();
	}
}

bool_t LoggerManager::Init(string_t cfg_path)
{
	fopen_s(&file_, cfg_path.c_str(), "a+");

	return true;
}

void LoggerManager::Update()
{
	for_each(iter, delayMsg_)
	{
		DoLog(*iter);
	}
	delayMsg_.clear();
}

NS_RENDER_END