#pragma once

#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/Task/ITask.h>

NS_RENDER_BEGIN

template<typename _TResource>
class Loader : ITask
{
public:
	Loader(string_t path, function_t<void(_TResource*)> loaded)
		: path_(path) , loaded_(loaded) { }

	virtual void BeginTask() override;
	virtual void EndTask() override;

protected:
	string_t path_;
	function_t<void(_TResource*)> loaded_ = nullptr;
	_TResource* resource_ = nullptr;
};

NS_RENDER_END