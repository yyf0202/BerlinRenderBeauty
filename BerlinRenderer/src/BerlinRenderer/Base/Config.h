#pragma once

#define NS_RENDER_BEGIN		namespace BRE {
#define NS_RENDER_END		}
#define RENDER				BRE::
#define USE_RENDER			using namespace BRE

#define OPEN_PROFILER 1

//#define OPEN_RENDER_API

#ifdef OPEN_RENDER_API
#define RENDER_API __declspec(dllexport)
#else
#define RENDER_API
#endif

#define DYNAMIC_CAST	dynamic_cast
#define SAFE_DEL(_ptr_) do { if (_ptr_ != nullptr) { delete _ptr_; _ptr_ = nullptr; } } while (false)


#pragma region  include
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <memory>
#include <stack>
#include <queue>

#include "Noncopyable.h"
#include <glad/glad.h>
#include <KHR/khrplatform.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#pragma endregion


#ifndef _STDINT
typedef unsigned char uint8_t;
typedef char int8_t;

typedef short int16_t;
typedef unsigned short uint16_t;

typedef int int32_t;
typedef unsigned int uint32_t;

typedef long long int64_t;
typedef unsigned long long uint64_t;
#endif

#pragma region define type
typedef unsigned char	byte_t;
typedef float			float_t;
typedef double			double_t;
typedef bool			bool_t;
typedef void*			ptr_t;
typedef					int32_t error_t;
typedef std::string		string_t;
typedef glm::vec2		vec2_t;
typedef glm::vec3		vec3_t;
typedef glm::mat4		mat4_t;

#define vector_t		std::vector
#define hash_t			std::unordered_map
#define list_t			std::list
#define stack_t			std::stack
#define queue_t			std::queue
#define shared_ptr_t	std::shared_ptr
#define unique_ptr_t	std::unique_ptr
#pragma endregion




#include <stdio.h>
#define LOG_ERROR	printf
#define LOG_INFO	printf
#define LOG_WARNING	printf

#define GL_LOG		printf

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



