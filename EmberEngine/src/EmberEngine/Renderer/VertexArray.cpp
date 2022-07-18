#include "EmberEnginePCH.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "EmberEngine/Platform/OpenGL/OpenGLVertexArray.h"

namespace EmberEngine
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case API::None:
			EMBER_REVERSE_ASSERT(true, "RendererAPI::None is not currently supported!");
			return nullptr;
		case API::OpenGL:
			return new OpenGLVertexArray();
		}

		EMBER_REVERSE_ASSERT(true, "Unknown RendererAPI!");
		return nullptr;
	}

	void VertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
	{

	}

	void VertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{

	}

	void VertexArray::Bind() const
	{

	}

	void VertexArray::UnBind() const
	{

	}
}