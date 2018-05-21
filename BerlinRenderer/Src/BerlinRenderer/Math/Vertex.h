#pragma once

#include <BerlinRenderer/Base/Config.h>

NS_RENDER_BEGIN

struct Vertex
{
	// Position
	vec3_t Position;
	// Normal
	vec3_t Normal;
	// TexCoords
	vec2_t TexCoords;
};

NS_RENDER_END