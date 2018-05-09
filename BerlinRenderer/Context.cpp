//0.1.1 
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////
#include "Context.h"
#include "Utils.h"

namespace BRE {
	Context::Context() {

	}

	Context::~Context() {

	}

	void Context::Suspend() {

	}

	void Context::Suspend() {

	}

	void Context::Resume() {

	}

	void Context::Destroy() {
	
	}

    Context& Context::Instance() {
		if (!context_instance_) {
			context_instance_ = MakeUniquePtr<Context>();
		}

		return *context_instance_;
	}

}