#pragma once

#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/Base/Singleton.h>
#include <BerlinRenderer/Base/Timer.h>

NS_RENDER_BEGIN

class SimpleProfiler : public Singleton<SimpleProfiler>
{
private:
	struct MemBlock
	{
		string_t ObjName;
		string_t Filename;
		uint32_t CodeLine;
		ptr_t Ptr;
	};

	struct CpuBlock
	{
		string_t FuncName;
		uint32_t Frames;
		Timer CostTimer;
		vector_t<CpuBlock*> SubFuncs;
	};

public:
	void AddMemBlock(const char* objName, const char* fileName, uint32_t codeLine, ptr_t ptr);
	void AddMemBlock(MemBlock block);
	void RemMemBlock(ptr_t ptr);

	void BeginRegion(const char* func);
	void EndRegion();

	void SetKeepFrames(uint32_t v) { keepFrames_ = v; }
	uint32_t GetKeepFrames() { return keepFrames_; }

	template<typename _Ty, typename... _Arg>
	_Ty* new_adapt(const char* obj_name, const char* filename, int codeline, _Arg... args)
	{
		_Ty* ret = new _Ty(args...);
		AddMemBlock(obj_name, filename, codeline, ret);
		return ret;
	}

	void del_adapt(void* ptr)
	{
		RemMemBlock(ptr);
		SAFE_DEL(ptr);
	}

private:

private:
	hash_t<ptr_t, MemBlock> memorys_;
	queue_t<CpuBlock*> framesCpuInfos_;
	stack_t<CpuBlock*> cpuTrace_;
	uint32_t curFrames_ = 0;
	uint32_t keepFrames_ = 100;
};

class CpuRegion
{
public:
	CpuRegion(const char* name)
	{
		SimpleProfiler::GetInstance().BeginRegion(name);
	}
	~CpuRegion()
	{
		SimpleProfiler::GetInstance().EndRegion();
	}
};

#ifdef OPEN_PROFILER
#define PROFILE_FUNCTION() RENDER CpuRegion _region_##__FUNCTION__ (__FUNCTION__)
#define NEW(_type_, ...) do {  } while(false) SimpleProfiler::GetInstance().new_adapt<_type_>(typeid(_type_).name(), __FILE__, __LINE__, __VA_ARGS__)
#define DEL(_ptr_) SimpleProfiler::GetInstance().del_adapt(_ptr_)
#else
#define PROFILE_FUNCTION() (void*)0
#define NEW(_type_, ...) (void*)0
#define DELETE(_ptr_) (void*)0
#endif

NS_RENDER_END