//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#pragma once
#include <BerlinRenderer/Base/Config.h>

NS_RENDER_BEGIN

template <typename T, typename... Args>
inline std::unique_ptr<T> MakeUniquePtrHelper(std::false_type, Args&&... args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename T, typename... Args>
inline std::unique_ptr<T> MakeUniquePtrHelper(std::true_type, size_t size)
{
	static_assert(0 == std::extent<T>::value,
		"make_unique<T[N]>() is forbidden, please use make_unique<T[]>().");

	return std::make_unique<T>(size);
}

template <typename T, typename... Args>
inline std::unique_ptr<T> MakeUniquePtr(Args&&... args)
{
	return MakeUniquePtrHelper<T>(std::is_array<T>(), std::forward<Args>(args)...);
}

NS_RENDER_END