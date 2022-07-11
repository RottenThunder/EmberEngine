#pragma once
#include <string>
#include "EmberEngine/Core/Base.h"

namespace EmberEngine
{
	class Shader
	{
	private:
		uint32_t RendererID;
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind() const;
		void UnBind() const;
	};
}