#include "EmberEnginePCH.h"
#include "Shader.h"
#include "Renderer.h"
#include "EmberEngine/Platform/OpenGL/OpenGLShader.h"

namespace EmberEngine
{
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case API::None:
			EMBER_REVERSE_ASSERT(true, "RendererAPI::None is not currently supported!");
			return nullptr;
		case API::OpenGL:
			return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		EMBER_REVERSE_ASSERT(true, "Unknown RendererAPI!");
		return nullptr;
	}
}