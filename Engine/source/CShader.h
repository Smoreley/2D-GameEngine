#pragma once
#include <GL\glew.h>

namespace Beserk {

	class CShader
	{
	public:
		CShader();
		~CShader();

		bool CreateShader();

		bool LoadShader(const char* fileName, GLuint* shaderHandle);
		bool CompileShader();

	private:

	};

}