//0.1.1 
//���δ��� (2018.05.09)
//
// �޸ļ�¼
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