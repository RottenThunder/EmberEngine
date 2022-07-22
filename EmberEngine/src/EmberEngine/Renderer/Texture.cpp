#include "EmberEnginePCH.h"
#include "Texture.h"
#include "Renderer.h"
#include "EmberEngine/Platform/OpenGL/OpenGLTexture.h"

namespace EmberEngine
{
	Ref<Texture> Texture::Create(const std::string& filePath)
	{
		switch (Renderer::GetAPI())
		{
		case API::None:
			EMBER_REVERSE_ASSERT(true, "RendererAPI::None is not currently supported!");
			return nullptr;
		case API::OpenGL:
			return std::make_shared<OpenGLTexture>(filePath);
		}

		EMBER_REVERSE_ASSERT(true, "Unknown RendererAPI!");
		return nullptr;
	}
}