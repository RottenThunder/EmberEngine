#pragma once
#include "EmberEngine/Renderer/Shader.h"

namespace EmberEngine
{
	class OpenGLShader : public Shader
	{
	private:
		uint32_t RendererID;
		void Compile(const std::unordered_map<uint32_t, std::string>& shaderSources);
		std::string ReadFile(const std::string& filePath);
		std::unordered_map<uint32_t, std::string> PreProcess(const std::string& source);
	public:
		OpenGLShader(const std::string& filepath);
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void UploadUniformInt(const std::string& name, int32_t value) override;
		virtual void UploadUniformFloat(const std::string& name, float value) override;
		virtual void UploadUniformVector2f(const std::string& name, const Vector2& vector) override;
		virtual void UploadUniformVector3f(const std::string& name, const Vector3& vector) override;
		virtual void UploadUniformVector4f(const std::string& name, const Vector4& vector) override;
		virtual void UploadUniformVector4f(const std::string& name, const Colour& colour) override;
		virtual void UploadUniformMatrix4x4(const std::string& name, const Matrix4x4& matrix) override;
	};
}