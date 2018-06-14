
#include "Resource.h"
#include <BerlinRenderer/Task/TaskManager.h>
#include <BerlinRenderer/Base/Context.h>

NS_RENDER_BEGIN

Resource::Resource()
{

}

Resource::Resource(string_t path)
	: path_(path)
{

}

void Resource::BeginTask()
{
	Load(path_);
}

void Resource::EndTask()
{
	EndLoad();
}

void Resource::BeginLoad(string_t path)
{
	path_ = path;
	Context::GetInstance().TaskManagerInstance().AddTask(this);
}

void Resource::EndLoad()
{
	if (loaded_ != nullptr)
	{
		loaded_(this);
	}
}

NS_RENDER_END