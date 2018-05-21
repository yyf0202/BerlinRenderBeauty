#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

class TriangleDraw {
	float vertices[9] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

public:
	void Draw();
};