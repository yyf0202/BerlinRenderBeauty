#include "Mesh.h"

NS_RENDER_BEGIN

Mesh::Mesh() : vertices_(0), indices_(0), textures_(0)
{

}

Mesh::Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture2D> textures)
{
	this->vertices_ = vertices;
	this->indices_ = indices;
	this->textures_ = textures;
	this->setupMesh();
}

void Mesh::Load(string_t name)
{

}

void Mesh::setupMesh()
{
	//gen vao
	glGenVertexArrays(1, &this->vao_);
	glBindVertexArray(this->vao_);

	//gen vbo
	glGenBuffers(1, &this->vbo_);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_);
	glBufferData(GL_ARRAY_BUFFER, this->vertices_.size() * sizeof(Vertex), &this->vertices_[0], GL_STATIC_DRAW);

	//gen veo
	glGenBuffers(1, &this->ebo_);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo_);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices_.size() * sizeof(GLuint), &this->indices_[0], GL_STATIC_DRAW);

	//enable vertext attribs
	glEnableVertexAttribArray(VERTEX_SHADER_ATTRIBUTE_POSITION_LAYOUT);
	glVertexAttribPointer(VERTEX_SHADER_ATTRIBUTE_POSITION_LAYOUT, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(VERTEX_SHADER_ATTRIBUTE_NORMAL_LAYOUT);
	glVertexAttribPointer(VERTEX_SHADER_ATTRIBUTE_NORMAL_LAYOUT, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));
	glEnableVertexAttribArray(VERTEX_SHADER_ATTRIBUTE_UV_LAYOUT);
	glVertexAttribPointer(VERTEX_SHADER_ATTRIBUTE_UV_LAYOUT, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));

	//unbind vao
	glBindVertexArray(0);
}

NS_RENDER_END