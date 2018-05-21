#pragma once

#define NS_RENDER_BEGIN		namespace BRE {
#define NS_RENDER_END		}
#define RENDER				BRE::
#define USE_RENDER			


//#define OPEN_RENDER_API

#ifdef OPEN_RENDER_API
#define RENDER_API __declspec(dllexport)
#else
#define RENDER_API
#endif

#include "Noncopyable.h"

// define type
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <memory>

#ifndef _STDINT
typedef unsigned char byte_t;
typedef unsigned char uint8_t;
typedef char int8_t;

typedef short int16_t;
typedef unsigned short uint16_t;

typedef int int32_t;
typedef unsigned int uint32_t;

typedef long long int64_t;
typedef unsigned long long uint64_t;
#endif

typedef float float_t;
typedef double double_t;

typedef void* ptr_t;

typedef int32_t error_t;

typedef std::string string_t;
#define vector_t std::vector
#define hash_t std::unordered_map
#define list_t std::list
#define shared_ptr_t std::shared_ptr
#define unique_ptr_t std::unique_ptr

//#define GLEW_STATIC

//#define GLEW_STATIC

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GLFW/glfw3.h>


#include <glm/glm.hpp>
typedef glm::vec2 vec2_t;
typedef glm::vec3 vec3_t;
typedef glm::mat4 mat4_t;