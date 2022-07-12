#pragma once
#include "EmberEngine/Core/Base.h"
#include "EmberEngine/Renderer/Buffer.h"

namespace EmberEngine
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	private:
		uint32_t RendererID;
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const;
		virtual void UnBind() const;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	private:
		uint32_t RendererID;
		uint32_t Count;
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const;
		virtual void UnBind() const;

		virtual uint32_t GetCount() const { return Count; }
	};
}