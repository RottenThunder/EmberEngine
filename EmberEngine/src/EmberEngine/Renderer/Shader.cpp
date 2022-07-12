#include "EmberEnginePCH.h"
#include "Shader.h"
#include <glad/glad.h>

namespace EmberEngine
{
	Shader::Shader(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		//Create an empty vertex shader handle
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

		//Send the vertex shader source code to GL
		//Note that std::string's .c_str is NULL character terminated.
		const GLchar* source = vertexSrc.c_str();
		glShaderSource(vertexShader, 1, &source, 0);

		//Compile the vertex shader
		glCompileShader(vertexShader);

		GLint isCompiled = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			//The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

			//We don't need the shader anymore.
			glDeleteShader(vertexShader);

			EMBER_REVERSE_ASSERT(true, "Failed to compile Vertex Shader!\n" << infoLog.data());
			return;
		}

		//Create an empty fragment shader handle
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		//Send the fragment shader source code to GL
		//Note that std::string's .c_str is NULL character terminated.
		source = fragmentSrc.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);

		//Compile the fragment shader
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			//The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

			//We don't need the shaders anymore. Don't leak shaders.
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			EMBER_REVERSE_ASSERT(true, "Failed to compile Fragment Shader!\n" << infoLog.data());
			return;
		}

		//Vertex and fragment shaders are successfully compiled.
		//Now time to link them together into a program.
		//Get a program object.
		RendererID = glCreateProgram();

		//Attach our shaders to our program
		glAttachShader(RendererID, vertexShader);
		glAttachShader(RendererID, fragmentShader);

		//Link our program
		glLinkProgram(RendererID);

		//Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(RendererID, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(RendererID, GL_INFO_LOG_LENGTH, &maxLength);

			//The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(RendererID, maxLength, &maxLength, &infoLog[0]);

			//We don't need the program anymore.
			glDeleteProgram(RendererID);
			//Don't leak shaders either.
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			EMBER_REVERSE_ASSERT(true, "Failed to Link Shaders!\n" << infoLog.data());
			return;
		}

		//Always detach shaders after a successful link.
		glDetachShader(RendererID, vertexShader);
		glDetachShader(RendererID, fragmentShader);
	}

	Shader::~Shader()
	{
		glDeleteProgram(RendererID);
	}

	void Shader::Bind() const
	{
		glUseProgram(RendererID);
	}

	void Shader::UnBind() const
	{
		glUseProgram(0);
	}
}