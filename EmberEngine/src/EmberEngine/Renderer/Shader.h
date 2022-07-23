#pragma once
#include <string>
#include "EmberEngine/Core/Base.h"
#include "EmberEngine/Maths/Vectors/Vector2.h"
#include "EmberEngine/Maths/Vectors/Vector3.h"
#include "EmberEngine/Maths/Vectors/Vector4.h"
#include "EmberEngine/Maths/Matrices/Matrix4x4.h"

namespace EmberEngine
{
	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void UploadUniformInt(const std::string& name, int32_t value) = 0;
		virtual void UploadUniformFloat(const std::string& name, float value) = 0;
		virtual void UploadUniformVector2f(const std::string& name, const Vector2& vector) = 0;
		virtual void UploadUniformVector3f(const std::string& name, const Vector3& vector) = 0;
		virtual void UploadUniformVector4f(const std::string& name, const Vector4& vector) = 0;
		virtual void UploadUniformMatrix4x4(const std::string& name, const Matrix4x4& matrix) = 0;

		static Ref<Shader> Create(const std::string& filePath);
		static Ref<Shader> Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};
}