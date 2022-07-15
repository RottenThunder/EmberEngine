#include "EmberEnginePCH.h"
#include "Buffer.h"
#include "Renderer.h"
#include "EmberEngine/Platform/OpenGL/OpenGLBuffer.h"

namespace EmberEngine
{
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			EMBER_REVERSE_ASSERT(true, "RendererAPI::None is not currently supported!");
			return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
		}

		EMBER_REVERSE_ASSERT(true, "Unknown RendererAPI!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			EMBER_REVERSE_ASSERT(true, "RendererAPI::None is not currently supported!");
			return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer(indices, count);
		}

		EMBER_REVERSE_ASSERT(true, "Unknown RendererAPI!");
		return nullptr;
	}
}