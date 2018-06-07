#pragma once
// Std. Includes
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
// GL Includes
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <assimp/types.h>

#include "Texture2D.h"

struct Vertex {
	// Position
	glm::vec3 Position;
	// Normal
	glm::vec3 Normal;
	// TexCoords
	glm::vec2 TexCoords;
};

//class Texture {
//public:
//	GLuint id;
//	string type;
//	string path;
//};

NS_RENDER_BEGIN

class Shader;

class Mesh {

public:
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture2D> textures;

	//for now 
	//TODO: define Texture type , return albedo texture
	GLuint GetDiffuseTexture() {
		return 0;
	}

	Mesh() : vertices(0), indices(0), textures(0)
	{

	}
	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture2D> textures)
	{
		this->vertices = vertices;
		this->indices = indices;
		this->textures = textures;

		this->setupMesh();
	}

	GLuint GetVertexArray() { 
		return VAO; 
	}

private:
	GLuint VAO, VBO, EBO;

	void setupMesh()
	{
		glGenVertexArrays(1, &this->VAO);
		glBindVertexArray(this->VAO);

		glGenBuffers(1, &this->VBO);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
		glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);

		glGenBuffers(1, &this->EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(SHADER_POSITION_LOCATION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(SHADER_NORMAL_LOCATION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(SHADER_UV_LOCATION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));

		//Unbind VAO
		glBindVertexArray(0);
	}
};

NS_RENDER_END
