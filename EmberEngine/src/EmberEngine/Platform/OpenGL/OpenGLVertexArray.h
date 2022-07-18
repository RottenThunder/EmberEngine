#pragma once
#include "EmberEngine/Renderer/VertexArray.h"

namespace EmberEngine
{
	class OpenGLVertexArray : public VertexArray
	{
	private:
		uint32_t RendererID;
		std::vector<Ref<VertexBuffer>> VertexBuffers;
		Ref<IndexBuffer> Index_Buffer;
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) override;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) override;

		virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const { return VertexBuffers; }
		virtual const Ref<IndexBuffer>& GetIndexBuffer() const { return Index_Buffer; }
	};
}