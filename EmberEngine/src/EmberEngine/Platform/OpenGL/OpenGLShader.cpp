#include "EmberEnginePCH.h"
#include "OpenGLShader.h"
#include <glad/glad.h>

namespace EmberEngine
{
	static GLenum ShaderTypeFromString(const std::string& type)
	{
		if (type == "vertex")
			return GL_VERTEX_SHADER;
		if (type == "fragment")
			return GL_FRAGMENT_SHADER;

		return 0;
	}

	OpenGLShader::OpenGLShader(const std::string& filePath)
	{
		std::string source = ReadFile(filePath);
		auto shaderSources = PreProcess(source);
		Compile(shaderSources);
	}

	OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		std::unordered_map<GLenum, std::string> sources;
		sources[GL_VERTEX_SHADER] = vertexSrc;
		sources[GL_FRAGMENT_SHADER] = fragmentSrc;
		Compile(sources);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(RendererID);
	}

	std::string OpenGLShader::ReadFile(const std::string& filePath)
	{
		std::string result;
		std::ifstream in(filePath, std::ios::in, std::ios::binary);
		if (in)
		{
			in.seekg(0, std::ios::end);
			result.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&result[0], result.size());
			in.close();
		}
		else
		{
			EMBER_REVERSE_ASSERT(true, "Could Not Open File: " << filePath);
		}

		return result;
	}

	std::unordered_map<GLenum, std::string> OpenGLShader::PreProcess(const std::string& source)
	{
		std::unordered_map<GLenum, std::string> shaderSources;

		const char* typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t position = source.find(typeToken, 0);

		while (position != std::string::npos)
		{
			size_t eol = source.find_first_of("\r\n", position);
			EMBER_ASSERT(eol != std::string::npos, "Syntax Error");
			size_t begin = position + typeTokenLength + 1;
			std::string type = source.substr(begin, eol - begin);
			EMBER_ASSERT(ShaderTypeFromString(type), "Invalid  or Unknown Shader Type Specified!");

			size_t nextLinePosition = source.find_first_not_of("\r\n", eol);
			position = source.find(typeToken, nextLinePosition);
			shaderSources[ShaderTypeFromString(type)] = source.substr(nextLinePosition, position - (nextLinePosition == std::string::npos ? source.size() - 1 : nextLinePosition));
		}

		return shaderSources;
	}

	void OpenGLShader::Compile(const std::unordered_map<GLenum, std::string>& shaderSources)
	{
		GLuint program = glCreateProgram();
		std::vector<GLenum> glShaderIDs;

		for (auto& kv : shaderSources)
		{
			GLenum type = kv.first;
			const std::string& source = kv.second;

			GLuint shader = glCreateShader(type);

			const GLchar* sourceCStr = source.c_str();
			glShaderSource(shader, 1, &sourceCStr, 0);

			glCompileShader(shader);

			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(shader);

				EMBER_REVERSE_ASSERT(true, "Failed to Compile Shader! " << infoLog.data());
				break;
			}

			glAttachShader(program, shader);
			glShaderIDs.push_back(shader);
		}

		glLinkProgram(program);

		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

			glDeleteProgram(program);

			for (auto id : glShaderIDs)
				glDeleteShader(id);

			EMBER_REVERSE_ASSERT(true, "Failed to Link Shaders! " << infoLog.data());
			return;
		}

		for (auto id : glShaderIDs)
			glDetachShader(program, id);

		RendererID = program;
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(RendererID);
	}

	void OpenGLShader::UnBind() const
	{
		glUseProgram(0);
	}

	void OpenGLShader::UploadUniformInt(const std::string& name, int32_t value)
	{
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniform1i(location, value);
	}

	void OpenGLShader::UploadUniformFloat(const std::string& name, float value)
	{
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniform1f(location, value);
	}

	void OpenGLShader::UploadUniformVector2f(const std::string& name, const Vector2& vector)
	{
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniform2f(location, vector.x, vector.y);
	}

	void OpenGLShader::UploadUniformVector3f(const std::string& name, const Vector3& vector)
	{
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniform3f(location, vector.x, vector.y, vector.z);
	}

	void OpenGLShader::UploadUniformVector4f(const std::string& name, const Vector4& vector)
	{
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
	}

	void OpenGLShader::UploadUniformVector4f(const std::string& name, const Colour& colour)
	{
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniform4f(location, colour.Red, colour.Green, colour.Blue, colour.Alpha);
	}

	void OpenGLShader::UploadUniformMatrix4x4(const std::string& name, const Matrix4x4& matrix)
	{
		GLint location = glGetUniformLocation(RendererID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, &matrix.x0);
	}
}