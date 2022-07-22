#include "EmberEnginePCH.h"
#include "Buffer.h"
#include "Renderer.h"
#include "EmberEngine/Platform/OpenGL/OpenGLBuffer.h"

namespace EmberEngine
{
	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case API::None:
			EMBER_REVERSE_ASSERT(true, "RendererAPI::None is not currently supported!");
			return nullptr;
		case API::OpenGL:
			return std::make_shared<OpenGLVertexBuffer>(vertices, size);
		}

		EMBER_REVERSE_ASSERT(true, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case API::None:
			EMBER_REVERSE_ASSERT(true, "RendererAPI::None is not currently supported!");
			return nullptr;
		case API::OpenGL:
			return std::make_shared<OpenGLIndexBuffer>(indices, count);
		}

		EMBER_REVERSE_ASSERT(true, "Unknown RendererAPI!");
		return nullptr;
	}
}