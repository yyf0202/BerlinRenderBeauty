#pragma once
using namespace std;

#include <BerlinRenderer\Base\Config.h>
#include <BerlinRenderer\Math\Vertex.h>
#include "Texture2D.h"

NS_RENDER_BEGIN

class Mesh : Resource {
public:
	Mesh();

	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture2D> textures);

	virtual void Load(string_t name) override;

	GLuint GetVertexArray() {
		return vao_;
	}

private:
	GLuint vao_;
	GLuint vbo_;
	GLuint ebo_;

	vector<Vertex> vertices_;
	vector<GLuint> indices_;
	vector<Texture2D> textures_;

	void setupMesh();
};

NS_RENDER_END
