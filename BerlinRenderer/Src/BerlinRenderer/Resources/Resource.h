#pragma once

#include <BerlinRenderer/Base/Config.h>
#include "IResource.h"

NS_RENDER_BEGIN

class RENDER_API Resource : public IResource
{
public:
	Resource();
	Resource(string_t path);

	virtual void Load(string_t path) = 0;

	virtual void BeginLoad(string_t path);
	virtual void EndLoad();

	virtual void BeginTask() override;
	virtual void EndTask() override;

	void SetLoaded(function_t<void(IResource*)> loaded) { loaded_ = loaded; }

protected:
	function_t<void(IResource*)> loaded_;
	string_t path_;
};

NS_RENDER_END