#pragma once
#include "EmberEngine/Renderer/VertexArray.h"

namespace EmberEngine
{
	class OpenGLVertexArray : public VertexArray
	{
	private:
		uint32_t RendererID;
		std::vector<std::shared_ptr<VertexBuffer>> VertexBuffers;
		std::shared_ptr<IndexBuffer> Index_Buffer;
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;

		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const { return VertexBuffers; }
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return Index_Buffer; }
	};
}