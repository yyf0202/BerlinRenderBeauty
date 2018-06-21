
#include "RectRender.h"
#include <BerlinRenderer/Resources/Material.h>
#include <BerlinRenderer/Profiler/Profiler.h>

NS_RENDER_BEGIN

RectRender::RectRender()
{
	static GLfloat vertices[] = {
		0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f
	};

	static GLuint indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	glGenBuffers(1, &ebo_);
	glGenBuffers(1, &vbo_);
	glGenVertexArrays(1, &vao_);

	glBindVertexArray(vao_);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(VERTEX_SHADER_ATTRIBUTE_POSITION_LAYOUT, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(VERTEX_SHADER_ATTRIBUTE_POSITION_LAYOUT);

	glVertexAttribPointer(VERTEX_SHADER_ATTRIBUTE_COLOR_LAYOUT, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(VERTEX_SHADER_ATTRIBUTE_COLOR_LAYOUT);

	glBindVertexArray(0);
}

void RectRender::Draw()
{
	PROFILE_FUNCTION();

	GetMaterial()->Use();
	glBindVertexArray(vao_);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

NS_RENDER_END