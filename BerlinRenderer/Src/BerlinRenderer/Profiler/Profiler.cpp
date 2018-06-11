
#include "Profiler.h"

NS_RENDER_BEGIN

void SimpleProfiler::AddMemBlock(const char* objName, const char* fileName, uint32_t codeLine, ptr_t ptr)
{
	AddMemBlock(MemBlock{ string_t(objName), string_t(fileName), codeLine, ptr });
}

void SimpleProfiler::AddMemBlock(MemBlock block)
{
	memorys_[block.Ptr] = block;
}

void SimpleProfiler::RemMemBlock(ptr_t ptr)
{
	auto fd = memorys_.find(ptr);
	if (fd == memorys_.end()) return;

	memorys_.erase(fd);
}

void SimpleProfiler::BeginRegion(const char* func)
{
	CpuBlock* block = new CpuBlock();
	CpuBlock* top = nullptr;

	if (cpuTrace_.size() == 0)
	{
		++curFrames_;

		framesCpuInfos_.push(block);
		while (framesCpuInfos_.size() > keepFrames_) framesCpuInfos_.pop();
	}
	else
	{
		top = cpuTrace_.top();
		top->SubFuncs.push_back(block);
	}
	cpuTrace_.push(block);

	block->FuncName = func;
	block->Frames = curFrames_;
	block->CostTimer.Begin();
}

void SimpleProfiler::EndRegion()
{
	auto cur = cpuTrace_.top();
	cur->CostTimer.End();
	cpuTrace_.pop();
}

NS_RENDER_END