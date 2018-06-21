
#include "TextureRender.h"
#include <BerlinRenderer/Resources/Texture2D.h>
#include <BerlinRenderer/Resources/Material.h>
#include <BerlinRenderer/Profiler/Profiler.h>
#include <BerlinRenderer/IO/LoggerManager.h>

NS_RENDER_BEGIN

static GLfloat vertices[] = {
	0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.0f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
	-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
	-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f,  1.0f, 0.0f
};

static GLuint indices[] = {
	0, 1, 3,
	1, 2, 3
};

static GLfloat uvs[] = {
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
};

TextureRender::TextureRender()
{
	glGenBuffers(1, &ebo_);
	glGenBuffers(1, &vbo_);
	glGenVertexArrays(1, &vao_);

	glBindVertexArray(vao_);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(VERTEX_SHADER_ATTRIBUTE_POSITION_LAYOUT);
	glVertexAttribPointer(VERTEX_SHADER_ATTRIBUTE_POSITION_LAYOUT, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

	glVertexAttribPointer(VERTEX_SHADER_ATTRIBUTE_COLOR_LAYOUT, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(VERTEX_SHADER_ATTRIBUTE_COLOR_LAYOUT);

	glEnableVertexAttribArray(VERTEX_SHADER_ATTRIBUTE_UV_LAYOUT);
	glVertexAttribPointer(VERTEX_SHADER_ATTRIBUTE_UV_LAYOUT, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6*sizeof(float)));

	glBindVertexArray(0);
}

void TextureRender::Draw()
{
	PROFILE_FUNCTION();

	if (tex_ == nullptr) return;

	glActiveTexture(GL_TEXTURE0);

	//mat_->SetMat4(MODEL_MATRIX, object_->GetWorldMatrix());
	//mat_->SetMat4(VIEW_MATRIX, camera->GetViewMatrix());
	//mat_->SetMat4(PROJECTION_MATRIX, camera->GetProjectionMatrix());

	tex_->Bind();
	GetMaterial()->Use();

	glBindVertexArray(vao_);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void TextureRender::SetTexture(Texture2D* tex)
{
	tex_ = tex;
}

NS_RENDER_END