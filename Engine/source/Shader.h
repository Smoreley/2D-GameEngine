#pragma once
#include <GL\glew.h>

namespace Beserk {

	class Shader
	{
	public:
		Shader();
		~Shader();

		bool CreateShader();

		bool LoadShader(const char* fileName, GLuint* shaderHandle);
		bool CompileShader();

	private:

	};

}