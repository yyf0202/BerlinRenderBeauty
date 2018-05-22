#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <BerlinRenderer\Base\Config.h>

NS_RENDER_BEGIN
class Shader
{
public:
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	~Shader();

	void Draw();

private :
	GLuint program_;
	bool compile_failed_;
	
};
NS_RENDER_END
#endif